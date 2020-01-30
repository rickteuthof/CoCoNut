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

// TODO only generate the functions for actual lifetimes?
void generate_rpt_headers(Config *c, FILE *fp) {
    array *nodes = c->nodes;
    out("#include \"lib/array.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include \"core/ast_memory.h\"\n");

    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);

        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            if (attr->type != AT_enum)
                continue;
            char *key = ccn_str_cat(n->id, attr->id);
            out("void ccn_%s_disallowed(%s *node, %s type);\n", key, n->id, attr->type_id);
            out("void ccn_%s_mandatory(%s *node, %s type);\n", key, n->id, attr->type_id);

            mem_free(key);
        }
    }
}

void generate_rpt_sources(Config *c, FILE *fp) {
    int indent = 0;
    array *nodes = c->nodes;

    out("#include \"lib/print.h\"\n");
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/ccn_reporting.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include \"core/ast_memory.h\"\n");
    out("#include <stdio.h>\n");
}

void generate_reporting_definitions(Config *c, FILE *fp) {
    generate_rpt_sources(c, fp);
}

// TODO: can optimize some if statemens away for example (->) is always true or when no range is specified.

static int generate_reporting_traversal_children(Node *n, int indent, FILE *fp) {
    for (int i = 0; i < array_size(n->children); ++i) {
        Child *child = array_get(n->children, i);
        
        // out_statement("printf(\"Printing adress of Node %s, \%\%p\n\", node->%s)", n->id, n->id);
        // out_statement("mark_ast_memory_manager_entry(node->%s)", n->id);


        // for (int j = 0; j < array_size(child->lifetimes); ++j) {
        //     Lifetime_t *lifetime = array_get(child->lifetimes, j);
        //     char *left_comp = lifetime->start->inclusive ? ">=" : ">";
        //     char *right_comp = lifetime->end->inclusive ? "<=" : "<";
        //     if (lifetime->start != NULL && lifetime->end != NULL) {
        //         out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp,
        //                      (unsigned long)lifetime->start->action_counter_id,
        //                      right_comp, (unsigned long)lifetime->end->action_counter_id);
                
        //         if (lifetime->type == LIFETIME_DISALLOWED) {
        //            out_statement("ccn_check_disallowed(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, child->id, n->id, child->id);
        //         } else {
        //             out_statement("ccn_check_mandatory(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, child->id, n->id, child->id);
        //         }

        //         out_end_if();
        //     }
        // }
    }
    return indent;
}

static int generate_reporting_traversal_attributes(Config *c, Node *n, int indent, FILE *fp) {
    // for (int i = 0; i < array_size(n->attrs); ++i) {
    //     Attr *attr = array_get(n->attrs, i);
    //     printf("Printing adress of Travelsal attribute %p\n", (void *)attr);

    for (int i = 0; i < array_size(n->attrs); i++) {
            Attr *attr = array_get(n->attrs, i);
            if (attr->construct) {
                out("printf(\"attribute id = %%s\", node->%s);\n", attr->id);
            } else {
                //res->%s = ", attr->id);
                out("printf(\"attribute type :");    
                if (attr->default_value) {
                    switch (attr->default_value->type) {
                    case AV_string:
                        out("String\nattribute value: %%s\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_int:
                        out("Integer\nattribute value: %%ld\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_uint:
                        out("Unsigned Integer\nattribute value: %%lu\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_float:
                        out("Float\nattribute value: %%f\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_double:
                        out("Double\nattribute value: %%f\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_bool:
                        out("Bool\nattribute value: %%lu\n\", node->%s)\";\n", attr->id);
                        break;
                    case AV_id:
                        out("NULL\"); // TODO: fix default value id\n");
                        break;
                    }
                } else {
                    switch (attr->type) {
                    case AT_int:
                    case AT_uint:
                    case AT_int8:
                    case AT_int16:
                    case AT_int32:
                    case AT_int64:
                    case AT_uint8:
                    case AT_uint16:
                    case AT_uint32:
                    case AT_uint64:
                    case AT_enum:
                        out("0;\n");
                        break;
                    case AT_float:
                    case AT_double:
                        out("0.0;\n");
                        break;
                    case AT_bool:
                        out("false;\n");
                        break;
                    case AT_string:
                    case AT_link:
                        out("NULL\");\n");
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    


        // for (int j = 0; j < array_size(attr->lifetimes); ++j) {
        //     Lifetime_t *lifetime = array_get(attr->lifetimes, j);
        //     char *left_comp = lifetime->start->inclusive ? ">=" : ">";
        //     char *right_comp = lifetime->end->inclusive ? "<=" : "<";
        //     if (lifetime->start != NULL && lifetime->end != NULL) {
        //         out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp,
        //                      (unsigned long)lifetime->start->action_counter_id,
        //                      right_comp, (unsigned long)lifetime->end->action_counter_id);

        //         if (attr->type == AT_link) {
        //             if (lifetime->type == LIFETIME_DISALLOWED) {
        //                 out_statement("ccn_check_disallowed(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, attr->id, n->id, attr->id);
        //             } else {
        //                 out_statement("ccn_check_mandatory(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, attr->id, n->id, attr->id);
        //             }
        //         } else {
        //             Enum *enm = find_enum(c->enums, attr->type_id);
        //             if (enm == NULL) continue;
        //             char *key = ccn_str_cat(n->id, attr->id);

        //             char *value = lifetime->original_value == NULL ? "NULL" : lifetime->original_value;
        //             if (lifetime->type == LIFETIME_DISALLOWED) {
        //                 out_statement("ccn_%s_disallowed(node, %s_%s)", key, enm->prefix, value);
        //             } else {
        //                 out_statement("ccn_%s_mandatory(node, %s_%s)", key, enm->prefix, value);
        //             }
        //         }
        //         out_end_if();
        //     }
        // }
    //}
    return indent;
}

void generate_reporting_traversal(Config *c, FILE *fp) {
    int indent = 0;
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/traversal-_CCN_RPT.h\"\n");
    out("#include \"generated/ccn_reporting.h\"\n");
    out("#include \"lib/memory.h\"\n");
    out("#include \"core/ast_memory.h\"\n");
    out("#include <stdio.h>\n");
    out_struct("Info");
    out_field("void *none");
    out_struct_end();
    out_start_func("Info *_CCN_RPT_createinfo(void)");
    out_statement("return NULL");
    out_end_func();

    out_start_func("void _CCN_RPT_freeinfo(Info *info)");
    out_statement("mem_free(info)");
    out_end_func();
    for (int i = 0; i < array_size(c->nodes); ++i) {
        Node *n = array_get(c->nodes, i);
        out_start_func("void _CCN_RPT_%s(%s *node, Info *info)", n->id, n->id);
        //out_statement("printf(\"Printing adress of Node, \%\%p\\n\", node)");
        //out_statement("print_ast_memory_manager_entry(node)");

        //indent = generate_marking_traversal_children(n, indent, fp);
        indent = generate_reporting_traversal_attributes(c, n, indent, fp);

        // for (int j = 0; j < array_size(n->children); ++j) {
        //     Child *child = array_get(n->children, j);
        //     out_statement("trav_%s_%s(node, info)", n->id, child->id);
        // }
        out_statement("return");
        out_end_func();
    }
}

void generate_reporting_headers(Config *c, FILE *fp) {
    generate_rpt_headers(c, fp);
}
