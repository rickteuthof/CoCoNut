#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "cocogen/ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/str-ast.h"

#include "lib/set_implementations.h"
#include "lib/array.h"
#include "lib/memory.h"
#include "lib/smap.h"
#include "lib/str.h"


// TODO only generate the functions for actual lifetimes?
void generate_headers(Config *c, FILE *fp) {
    array *nodes = c->nodes;
    out("#include \"lib/array.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        out("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame);\n", n->id, n->id);
        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            char *key = ccn_str_cat(n->id, child->id);
            out("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame);\n", key, n->id);
            mem_free(key);
        }
        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            char *key = ccn_str_cat(n->id, attr->id);
            out("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame);\n", key, n->id);
            mem_free(key);
        }
    }
}

Enum *find_enum(array *enums, char *id) {
    for (int i = 0; i < array_size(enums); i++) {
        Enum *e = array_get(enums, i);
        if (ccn_str_equal(e->id, id)) {
            return e;
        }
    }
    return NULL;
}

void generate_sources(Config *c, FILE *fp) {
    int indent = 0;
    array *nodes = c->nodes;
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include <stdio.h>\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        out_start_func("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame)", n->id, n->id);
        out_begin_if("frame->type == CCN_CHK_DISALLOWED && node != NULL");
        out_statement("printf(\"[CHK] Error: node %s disallowed but present in the AST.\\n\")", n->id);
        out_end_if();
        out_end_func();

        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            char *key = ccn_str_cat(n->id, child->id);
            out_start_func("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame)", key, n->id);
            out_begin_if("frame->type == CCN_CHK_DISALLOWED && node != NULL && node->%s != NULL", child->id);
            out_statement("printf(\"[chk] error: node %s has a child of type %s, but this type is disallowed.\\n\")", n->id, child->id);
            out_end_if();
            out_begin_if("frame->type == CCN_CHK_MANDATORY && node != NULL && node->%s == NULL", child->id);
            out_statement("printf(\"[chk] error: child %s is mandatory on node %s, however is not present.\\n\")", child->id, n->id);
            out_end_if();
            mem_free(key);
            out_end_func();
        }

        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            if (attr->type != AT_enum) {
                continue;
            }
            Enum *enm = find_enum(c->enums, attr->type_id);
            if (enm == NULL) continue;
            char *key = ccn_str_cat(n->id, attr->id);
            out_start_func("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame)", key, n->id);
            out_begin_if("frame->type == CCN_CHK_DISALLOWED && node != NULL && node->%s != %s_NULL", attr->id, enm->prefix);
            out_statement("printf(\"[chk] error: node %s has an attribute of type %s, but this type is disallowed.\\n\")", n->id, attr->type_id);
            out_end_if();
            out_begin_if("frame->type == CCN_CHK_MANDATORY && node != NULL && node->%s == %s_NULL", attr->id, enm->prefix);
            out_statement("printf(\"[chk] error: attribute type %s is mandatory on node %s, however is not present.\\n\")", attr->type_id, n->id);
            out_end_if();
            mem_free(key);
            out_end_func();

        }
    }
}

void generate_consistency_definitions(Config *c, FILE *fp) {
    generate_sources(c, fp);
}

void generate_check_traversal(Config *c, FILE *fp) {
    int indent = 0;
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/traversal-_CCN_CHK.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include \"lib/memory.h\"\n");
    out_struct("Info");
    out_field("void *none");
    out_struct_end();
    out_start_func("Info *_CCN_CHK_createinfo(void)");
    out_statement("return NULL");
    out_end_func();

    out_start_func("void _CCN_CHK_freeinfo(Info *info)");
    out_statement("mem_free(info)");
    out_end_func();
    for (int i = 0; i < array_size(c->nodes); ++i) {
        Node *n = array_get(c->nodes, i);
        out_start_func("void _CCN_CHK_%s(%s *node, Info *info)", n->id, n->id);
        out_statement("phase_driver_t *pd = _get_phase_driver()");
        out_statement("ccn_chk_frame_t *frame = smap_retrieve(pd->consistency_map, \"%s\")", n->id);
        out_begin_if("frame != NULL");
        out_statement("ccn_chk_%s(node, frame)", n->id);
        out_end_if();
        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            char *key = ccn_str_cat(n->id, child->id);
            out_statement("frame = smap_retrieve(pd->consistency_map, \"%s\")", key);
            out_begin_if("frame != NULL");
            out_statement("ccn_chk_%s(node, frame)", key);
            out_end_if();
            mem_free(key);
        }

        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            if (attr->type != AT_enum) continue;
            char *key = ccn_str_cat(n->id, attr->id);
            out_statement("frame = smap_retrieve(pd->consistency_map, \"%s\")", key);
            out_begin_if("frame != NULL");
            out_statement("ccn_chk_%s(node, frame)", key);
            out_end_if();
            mem_free(key);
        }


        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            out_statement("trav_%s_%s(node, info)", n->id, child->id);
        }
        out_end_func();
    }
}

void generate_consistency_headers(Config *c, FILE *fp) {
    generate_headers(c, fp);
}
