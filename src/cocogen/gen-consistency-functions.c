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

#include <assert.h>

Enum *find_enum(array *enums, char *id) {
    assert(id != NULL);
    assert(enums != NULL);
    for (int i = 0; i < array_size(enums); i++) {
        Enum *e = array_get(enums, i);
        if (ccn_str_equal(e->id, id)) {
            return e;
        }
    }
    return NULL;
}


// TODO only generate the functions for actual lifetimes?
void generate_headers(Config *c, FILE *fp) {
    array *nodes = c->nodes;
    out("#include \"lib/array.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        out("void ccn_chk_%s(%s *node, enum ccn_chk_types type);\n", n->id, n->id);
        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            char *key = ccn_str_cat(n->id, child->id);
            out("void ccn_chk_%s(%s *node, enum ccn_chk_types type);\n", key, n->id);
            mem_free(key);
        }
        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            char *key = ccn_str_cat(n->id, attr->id);
            out("void ccn_chk_%s(%s *node, enum ccn_chk_types type);\n", key, n->id);
            if (attr->type != AT_enum) {
                mem_free(key);
                continue;
            }
            Enum *enm = find_enum(c->enums, attr->type_id);
            if (enm == NULL) {
                mem_free(key);
                continue;
            }
            //out("void ccn_chk_%svalues(%s *node, struct ccn_chk_frame *frame);\n", key, n->id, attr->type_id);
            for (int k = 0; k < array_size(enm->values); ++k) {
                char *val = array_get(enm->values, k);
                out("void ccn_chk_%s%s(%s *node, enum ccn_chk_types type);\n", key, val, n->id);
            }
            mem_free(key);
        }
    }
}

void out_path(int indent, FILE *fp) {
    out_statement("path: ");
}

void generate_sources(Config *c, FILE *fp) {
    int indent = 0;
    array *nodes = c->nodes;

    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include <stdio.h>\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        out_start_func("void ccn_chk_%s(%s *node, enum ccn_chk_types type)", n->id, n->id);
        out_statement("phase_driver_t *pd = _get_phase_driver()");
        out_begin_if("type == CCN_CHK_DISALLOWED && node != NULL");
        out_statement("printf(\"[CCN CHK] error:\\n\")"); // Maybe color this?, probably exit as well.
        out_statement("printf(\"Node %s disallowed but present in the AST.\\n\")", n->id);
        out_statement("printf(\"Current action: %%s\\n\", pd->current_action)");
        out_statement("_print_path()");
        out_statement("exit(1)");
        out_end_if();
        out_end_func();

        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            char *key = ccn_str_cat(n->id, child->id);
            out_start_func("void ccn_chk_%s(%s *node, enum ccn_chk_types type)", key, n->id);
            out_statement("phase_driver_t *pd = _get_phase_driver()");
            out_begin_if("type == CCN_CHK_DISALLOWED && node != NULL && node->%s != NULL", child->id);
            out_statement("printf(\"[CCN CHK] error:\\n\")");
            out_statement("printf(\"Node %s has a child of type %s, but this type is disallowed.\\n\")", n->id, child->id);
            out_statement("printf(\"Current action: %%s\\n\", pd->current_action)");
            out_statement("_print_path()");
            out_statement("exit(1)");
            out_statement("exit(1)");
            out_end_if();
            out_begin_if("type == CCN_CHK_MANDATORY && node != NULL && node->%s == NULL", child->id);
            out_statement("printf(\"[CCN CHK] error:\\n\")");
            out_statement("printf(\"Child %s is mandatory on node %s, however is not present.\\n\")", child->id, n->id);
            out_statement("printf(\"Current action: %%s\\n\", pd->current_action)");
            out_statement("_print_path()");
            out_statement("exit(1)");
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
            out_start_func("void ccn_chk_%s(%s *node, enum ccn_chk_types type)", key, n->id);
            out_statement("phase_driver_t *pd = _get_phase_driver()");
            out_begin_if("type == CCN_CHK_DISALLOWED && node != NULL && node->%s != %s_NULL", attr->id, enm->prefix);
            out_statement("printf(\"[CCN] CHK error: node %s has an attribute of type %s, but this type is disallowed.\\n\")", n->id, attr->type_id);
            out_end_if();
            out_begin_if("type == CCN_CHK_MANDATORY && node != NULL && node->%s == %s_NULL", attr->id, enm->prefix);
            out_statement("printf(\"[CCN CHK] error:\\n\")");
            out_statement("printf(\"Attribute type %s is mandatory on node %s, however is not present.\\n\")", attr->type_id, n->id);
            out_statement("printf(\"Current action: %%s\\n\", pd->current_action)");
            out_statement("_print_path()");
            out_statement("exit(1)");
            out_end_if();
            out_end_func();


            for (int k = 0; k < array_size(enm->values); ++k) {
                char *val = array_get(enm->values, k);
                out_start_func("void ccn_chk_%s%s(%s *node, enum ccn_chk_types type)", key, val, n->id);
                out_statement("phase_driver_t *pd = _get_phase_driver()");
                out_begin_if("type == CCN_CHK_DISALLOWED && node != NULL && node->%s == %s_%s", attr->id, enm->prefix, val);
                out_statement("printf(\"[CCN CHK] error:\\n\")");
                out_statement("printf(\"node: %s attribute type %s has value %s, which is disallowed.\\n\")", n->id, attr->type_id, val);
                out_statement("printf(\"Current action: %%s\\n\", pd->current_action)");
                out_statement("_print_path()");
                out_statement("exit(1)");
                out_end_if();
                out_end_func();
            }

            mem_free(key);
        }
    }
}

void generate_consistency_definitions(Config *c, FILE *fp) {
    generate_sources(c, fp);
}

// TODO: can optimize some if statemens away for example (->) is always true or when no range is specified.

int generate_check_traversal_children(Node *n, int indent, FILE *fp) {
    for (int i = 0; i < array_size(n->children); ++i) {
        Child *child = array_get(n->children, i);
        for (int j = 0; j < array_size(child->lifetimes); ++j) {
            Lifetime_t *lifetime = array_get(child->lifetimes, j);
            char *left_comp = lifetime->start->inclusive ? ">=" : ">";
            char *right_comp = lifetime->end->inclusive ? "<=" : "<";
            if (lifetime->start != NULL && lifetime->end != NULL) {
                out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp,
                             (unsigned long)lifetime->start->action_counter_id,
                             right_comp, (unsigned long)lifetime->end->action_counter_id);
                out_statement("ccn_chk_%s(node, %s)", lifetime->key, lifetime->start->type);
                out_end_if();
            }
        }
    }
    return indent;
}

int generate_check_traversal_attributes(Node *n, int indent, FILE *fp) {
    for (int i = 0; i < array_size(n->attrs); ++i) {
        Attr *attr = array_get(n->attrs, i);
        for (int j = 0; j < array_size(attr->lifetimes); ++j) {
            Lifetime_t *lifetime = array_get(attr->lifetimes, j);
            char *left_comp = lifetime->start->inclusive ? ">=" : ">";
            char *right_comp = lifetime->end->inclusive ? "<=" : "<";
            if (lifetime->start != NULL && lifetime->end != NULL) {
                out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp,
                             (unsigned long)lifetime->start->action_counter_id,
                             right_comp, (unsigned long)lifetime->end->action_counter_id);

                // TODO its nice to group values into 1 if statement. However we need change the checking of lifetimes then.
                // Because it currently checks for a key so every value gets its own lifetime and thus key.
                // So value = {v1, v2} -> valuev1 and valuev2. This makes it easier to check if conficlingting lifetimes are present.
                /*if (lifetime->values != NULL && array_size(lifetime->values) > 0) {
                    for (int k = 0; k < array_size(lifetime->values); ++k) {
                        char *val = array_get(lifetime->values, k);
                        out_statement("ccn_chk_%s%s(node, %s)", lifetime->key, val, lifetime->start->type);
                    }
                } else {*/
                out_statement("ccn_chk_%s(node, %s)", lifetime->key, lifetime->start->type);
                out_end_if();
            }
        }
    }
    return indent;
}

void generate_check_traversal(Config *c, FILE *fp) {
    int indent = 0;
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/traversal-_CCN_CHK.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include \"lib/memory.h\"\n");
    out("#include <stdio.h>\n");
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
        for (int j = 0; j < array_size(n->lifetimes); ++j) {
            Lifetime_t *lifetime = array_get(n->lifetimes, j);
            char *left_comp = lifetime->start->inclusive ? ">=" : ">";
            char *right_comp = lifetime->end->inclusive ? "<=" : "<";
            if (lifetime->start != NULL && lifetime->end != NULL) {
                out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp, (unsigned long)lifetime->start->action_counter_id, right_comp, (unsigned long)lifetime->end->action_counter_id);
                out_statement("ccn_chk_%s(node, %s)", lifetime->key, lifetime->start->type);
                out_end_if();
            }
        }
        indent = generate_check_traversal_children(n, indent, fp);
        indent = generate_check_traversal_attributes(n, indent, fp);

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
