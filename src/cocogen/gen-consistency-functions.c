#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "cocogen/ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/str-ast.h"

#include "lib/set_implementations.h"
#include "lib/array.h"
#include "lib/memory.h"
#include "lib/smap.h"

// TODO only generate the functions for actual lifetimes?
void generate_headers(Config *c, FILE *fp) {
    array *nodes = c->nodes;
    out("#include \"lib/array.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        out("void ccn_chk_%s(%s *node, struct ccn_chk_frame *frame);\n", n->id, n->id);
    }
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
            out_statement("trav_%s_%s(node, info)", n->id, child->id);
        }
        out_end_func();
    }
}

void generate_consistency_headers(Config *c, FILE *fp) {
    generate_headers(c, fp);
}
