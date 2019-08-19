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

static Enum *find_enum(array *enums, char *id) {
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

        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            if (attr->type != AT_enum)
                continue;
            char *key = ccn_str_cat(n->id, attr->id);
            out("void CCN%sDisallowed(%s *node, %s type);\n", key, n->id, attr->type_id);
            out("void CCN%sMandatory(%s *node, %s type);\n", key, n->id, attr->type_id);

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

    out("#include \"lib/print.h\"\n");
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include <stdio.h>\n");
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);

        for (int j = 0; j < array_size(n->attrs); ++j) {
            Attr *attr = array_get(n->attrs, j);
            if (attr->type != AT_enum) {
                continue;
            }
            Enum *enm = find_enum(c->enums, attr->type_id);
            if (enm == NULL) continue;
            char *key = ccn_str_cat(n->id, attr->id);
            out_start_func("void CCN%sDisallowed(%s *node, %s type)", key, n->id, enm->id);
            out_statement("phase_driver_t *pd = _CCNgetPhaseDriver()");
            out_begin_if("type == %s_NULL", enm->prefix);
                out_begin_if("node->%s != %s_NULL", attr->id, enm->prefix);
                    out_statement("print_user_error(\"CCN CHK\", \"Attribute %s of node type %s disallowed but present in tree.\")", attr->id, n->id);
                    out_statement("abort()");
                out_end_if();
            out_end_if();
            out_begin_else();
                out_begin_if("node->%s == type", attr->id);
                    out_statement("print_user_error(\"CCN CHK\", \"Attribute %s of node type %s has value , which is disallowed.\")", attr->id, n->id);
                    out_statement("abort()");
                out_end_if();
            out_end_else();
            out_end_func();

            out_start_func("void CCN%sMandatory(%s *node, %s type)", key, n->id, enm->id);
            out_statement("phase_driver_t *pd = _CCNgetPhaseDriver()");
            out_begin_if("type == %s_NULL", enm->prefix);
                out_begin_if("node->%s == %s_NULL", attr->id, enm->prefix);
                    out_statement("print_user_error(\"CCN CHK\", \"Attribute %s of node type %s is mandatory but not present in tree.\")", attr->id, n->id);
                    out_statement("abort()");
                out_end_if();
            out_end_if();
            out_begin_else();
                out_begin_if("node->%s == type", attr->id);
                    out_statement("print_user_error(\"CCN CHK\", \"Attribute %s of node type %s has value , but value is required.\")", attr->id, n->id);
                    out_statement("abort()");
                out_end_if();
            out_end_else();
            out_end_func();


            mem_free(key);
        }
    }
}

void generate_consistency_definitions(Config *c, FILE *fp) {
    generate_sources(c, fp);
}

// TODO: can optimize some if statemens away for example (->) is always true or when no range is specified.

static int generate_check_traversal_children(Node *n, int indent, FILE *fp) {
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
                
                if (lifetime->type == LIFETIME_DISALLOWED) {
                    out_statement("CCNcheckDisallowed(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, child->id, n->id, child->id);
                } else {
                    out_statement("CCNcheckMandatory(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, child->id, n->id, child->id);
                }

                out_end_if();
            }
        }
    }
    return indent;
}

static int generate_check_traversal_attributes(Config *c, Node *n, int indent, FILE *fp) {
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

                if (attr->type == AT_link) {
                    if (lifetime->type == LIFETIME_DISALLOWED) {
                        out_statement("CCNcheckDisallowed(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, attr->id, n->id, attr->id);
                    } else {
                        out_statement("CCNcheckMandatory(node, offsetof(%s, %s), \"%s\", \"%s\")", n->id, attr->id, n->id, attr->id);
                    }
                } else {
                    Enum *enm = find_enum(c->enums, attr->type_id);
                    if (enm == NULL) continue;
                    char *key = ccn_str_cat(n->id, attr->id);

                    char *value = lifetime->original_value == NULL ? "NULL" : lifetime->original_value;
                    if (lifetime->type == LIFETIME_DISALLOWED) {
                        out_statement("CCN%sDisallowed(node, %s_%s)", key, enm->prefix, value);
                    } else {
                        out_statement("CCN%sMandatory(node, %s_%s)", key, enm->prefix, value);
                    }
                }
                out_end_if();
            }
        }
    }
    return indent;
}

static bool is_active_lifetime(Node *n) {
    if (array_size(n->lifetimes) > 0) {
        return true;
    }

    for (int i = 0; i < array_size(n->children); ++i) {
        Child *c = array_get(n->children, i);
        if (array_size(c->lifetimes) > 0) {
            return true;
        }
    }

    for (int i = 0; i < array_size(n->attrs); ++i) {
        Attr *attr = array_get(n->attrs, i);
        if (array_size(attr->lifetimes) > 0) {
            return true;
        }
    }

    return false;
}

void generate_check_traversal(Config *c, FILE *fp) {
    int indent = 0;
    out("#include \"generated/ast.h\"\n");
    out("#include \"generated/traversal-_CCN_CHK.h\"\n");
    out("#include \"generated/ccn_consistency_check.h\"\n");
    out("#include \"lib/memory.h\"\n");
    out("#include \"core/consist_checks.h\"\n");
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
        if (is_active_lifetime(n)) {
            out_statement("phase_driver_t *pd = _CCNgetPhaseDriver()");
        }

        for (int j = 0; j < array_size(n->lifetimes); ++j) {
            Lifetime_t *lifetime = array_get(n->lifetimes, j);
            char *left_comp = lifetime->start->inclusive ? ">=" : ">";
            char *right_comp = lifetime->end->inclusive ? "<=" : "<";
            out_begin_if("pd->action_id %s %lu && pd->action_id %s %lu", left_comp, 
                         (unsigned long)lifetime->start->action_counter_id, right_comp,
                         (unsigned long)lifetime->end->action_counter_id);
            
            if (lifetime->type == LIFETIME_DISALLOWED) {
                out_statement("CCNcheckDisallowed(node, 0, \"%s\", NULL)", n->id);
            } 
            out_end_if();
        }
        indent = generate_check_traversal_children(n, indent, fp);
        indent = generate_check_traversal_attributes(c, n, indent, fp);

        for (int j = 0; j < array_size(n->children); ++j) {
            Child *child = array_get(n->children, j);
            out_statement("trav_%s_%s(node, info)", n->id, child->id);
        }
        out_statement("return");
        out_end_func();
    }
}

void generate_consistency_headers(Config *c, FILE *fp) {
    generate_headers(c, fp);
}
