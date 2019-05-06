#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "cocogen/ast.h"
#include "cocogen/check-ast.h"
#include "cocogen/free-ast.h"
#include "cocogen/gen-phase-functions.h"
#include "cocogen/gen-subtree-functions.h"

#include "lib/str.h"
#include "lib/array.h"
#include "lib/memory.h"
#include "lib/print.h"
#include "lib/set.h"
#include "lib/smap.h"

struct Info {
    smap_t *enum_name;
    smap_t *enum_prefix;
    smap_t *node_name;
    smap_t *nodeset_name;
    smap_t *traversal_name;
    smap_t *phase_name;
    smap_t *pass_name;

    Config *config;
    Node *root_node;
    Phase *root_phase;
};

static struct Info *create_info(Config *config) {

    struct Info *info = (struct Info *)mem_alloc(sizeof(struct Info));

    info->enum_name = smap_init(32);
    info->enum_prefix = smap_init(32);
    info->node_name = smap_init(32);
    info->nodeset_name = smap_init(32);
    info->traversal_name = smap_init(32);
    info->phase_name = smap_init(32);
    info->pass_name = smap_init(32);

    info->config = config;
    info->root_node = NULL;
    info->root_phase = NULL;
    return info;
}

static void free_info(struct Info *info) {
    smap_free(info->enum_name);
    smap_free(info->enum_prefix);
    smap_free(info->node_name);
    smap_free(info->nodeset_name);
    smap_free(info->traversal_name);
    smap_free(info->phase_name);
    smap_free(info->pass_name);
    mem_free(info);
}

static void *check_name_exists(struct Info *info, char *name) {
    Enum *enum_orig;
    Node *node_orig;
    Nodeset *nodeset_orig;
    Traversal *traversal_orig;
    Phase *phase_orig;
    Pass *pass_orig;

    if ((enum_orig = smap_retrieve(info->enum_name, name)) != NULL)
        return enum_orig->id;
    if ((node_orig = smap_retrieve(info->node_name, name)) != NULL)
        return node_orig->id;
    if ((nodeset_orig = smap_retrieve(info->nodeset_name, name)) != NULL)
        return nodeset_orig->id;
    if ((traversal_orig = smap_retrieve(info->traversal_name, name)) != NULL)
        return traversal_orig->id;
    if ((phase_orig = smap_retrieve(info->phase_name, name)) != NULL)
        return phase_orig->id;
    if ((pass_orig = smap_retrieve(info->pass_name, name)) != NULL)
        return pass_orig->id;
    return NULL;
}

static int check_enums(array *enums, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(enums); ++i) {
        Enum *cur_enum = (Enum *)array_get(enums, i);
        void *orig_def;

        // TODO check if name of enum overlaps with autogen enum.
        if ((orig_def = check_name_exists(info, cur_enum->id)) != NULL) {
            print_error(cur_enum->id, "Redefinition of name '%s'",
                        cur_enum->id);
            print_note(orig_def, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->enum_name, cur_enum->id, cur_enum);
        }

        char *orig_prefix;
        // TODO check if prefix is not forbidden: NS_.
        if ((orig_prefix =
                 smap_retrieve(info->enum_prefix, cur_enum->prefix)) != NULL) {
            print_error(cur_enum->prefix, "Redefinition of prefix '%s'",
                        cur_enum->prefix);
            print_note(orig_prefix, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->enum_prefix, cur_enum->prefix, cur_enum->prefix);
        }
    }
    return error;
}

static int check_nodes(array *nodes, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(nodes); ++i) {
        Node *cur_node = (Node *)array_get(nodes, i);
        void *orig_def;

        if ((orig_def = check_name_exists(info, cur_node->id))) {
            print_error(cur_node->id, "Redefinition of name '%s'",
                        cur_node->id);
            print_note(orig_def, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->node_name, cur_node->id, cur_node);
        }

        if (cur_node->root) {
            if (info->root_node != NULL) {
                orig_def = info->root_node->id;
                print_error(cur_node->id,
                            "Duplicate declaration of root node");
                print_note(orig_def, "Previously declared here");
                error = 1;
            } else {
                info->root_node = cur_node;
            }
        }
    }
    return error;
}

static int check_nodesets(array *nodesets, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(nodesets); ++i) {
        Nodeset *cur_nodeset = (Nodeset *)array_get(nodesets, i);
        void *orig_def;

        if ((orig_def = check_name_exists(info, cur_nodeset->id)) != NULL) {
            print_error(cur_nodeset->id, "Redefinition of name '%s'",
                        cur_nodeset->id);
            print_note(orig_def, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->nodeset_name, cur_nodeset->id, cur_nodeset);
        }
    }
    return error;
}

static int check_phases(array *phases, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(phases); ++i) {
        Phase *cur_phase = (Phase *)array_get(phases, i);
        void *orig_def;
        if ((orig_def = check_name_exists(info, cur_phase->id)) != NULL) {
            print_error(cur_phase->id, "Redefinition of name '%s'",
                        cur_phase->id);
            print_note(orig_def, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->phase_name, cur_phase->id, cur_phase);
        }

        if (cur_phase->root != NULL) {
            Node *node_def = smap_retrieve(info->node_name, cur_phase->root);
            if (node_def == NULL) {
                print_error(cur_phase->root, "Not a valid node.");
                error = 1;
            }
            bool has_child_next = false;
            for (int j = 0; j < array_size(node_def->children); ++j) {
                Child *child = array_get(node_def->children, j);
                if (strcmp(child->id, "next") == 0) {
                    has_child_next = true;
                    break;
                }
            }
            if (! has_child_next) {
                print_error(cur_phase->root, "Specified root has no child named next.");
                error = 1;
            }
        }
    }
    return error;
}

static int check_passes(array *passes, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(passes); ++i) {
        Pass *cur_pass = (Pass *)array_get(passes, i);
        void *orig_def;

        if ((orig_def = check_name_exists(info, cur_pass->id)) != NULL) {
            print_error(cur_pass->id, "Redefinition of name '%s'",
                        cur_pass->id);
            print_note(orig_def, "Previously declared here");
        } else {
            smap_insert(info->pass_name, cur_pass->id, cur_pass);
        }
    }
    return error;
}

static int check_traversals(array *traversals, struct Info *info) {

    int error = 0;

    for (int i = 0; i < array_size(traversals); ++i) {
        Traversal *cur_traversal = (Traversal *)array_get(traversals, i);
        void *orig_def;

        if ((orig_def = check_name_exists(info, cur_traversal->id)) != NULL) {
            print_error(cur_traversal->id, "Redefinition of name '%s'",
                        cur_traversal->id);
            print_note(orig_def, "Previously declared here");
            error = 1;
        } else {
            smap_insert(info->traversal_name, cur_traversal->id,
                        cur_traversal);
        }
    }
    return error;
}

static int check_mandatory_phase(MandatoryPhase *phase, struct Info *info) {
    int error = 0;

    switch (phase->type) {
    case MP_single:
        if (smap_retrieve(info->phase_name, phase->value.single) == NULL) {
            print_error(phase->value.single, "Unknown mandatory phase '%s'",
                        phase->value.single);
            error = 1;
        }
        break;

    case MP_range:; // Crazy GCC won't allow declaration behind statement.

        PhaseRange *phase_range = phase->value.range;
        if (smap_retrieve(info->phase_name, phase_range->start) == NULL) {
            print_error(phase_range->start,
                        "Unknown mandatory phase range start '%s'",
                        phase_range->start);
            error = 1;
        }
        if (smap_retrieve(info->phase_name, phase_range->end) == NULL) {
            print_error(phase_range->end,
                        "Unknown mandatory phase range end '%s'",
                        phase_range->end);
            error = 1;
        }
        break;
    }

    // TODO: Check if there are no overlapping/duplicate phases.

    return error;
}

static int check_node(Node *node, struct Info *info) {
    int error = 0;

    smap_t *child_name = smap_init(16);

    if (node->children) {
        for (int i = 0; i < array_size(node->children); ++i) {
            Child *child = (Child *)array_get(node->children, i);
            Child *orig_child;

            // Check if there is no duplicate naming.
            if ((orig_child = smap_retrieve(child_name, child->id)) != NULL) {
                print_error(child->id,
                            "Duplicate name '%s' in children of node '%s'",
                            child->id, node->id);
                print_note(orig_child->id, "Previously declared here");
                error = 1;
            } else {
                smap_insert(child_name, child->id, child);
            }

            Node *child_node =
                (Node *)smap_retrieve(info->node_name, child->type);
            Nodeset *child_nodeset =
                (Nodeset *)smap_retrieve(info->nodeset_name, child->type);

            if (!child_node && !child_nodeset) {
                print_error(child->type,
                            "Unknown type '%s' of child '%s' of node '%s'",
                            child->type, child->id, node->id);
                error = 1;
            } else {
                child->node = child_node;
                child->nodeset = child_nodeset;
            }

            if (child_node && child_node == info->root_node) {
                print_error(
                    child->id,
                    "Child '%s' of node '%s' cannot use root node as type",
                    child->id, node->id);
                error = 1;
            }

            for (int i = 0; i < array_size(child->mandatory_phases); ++i) {
                MandatoryPhase *phase =
                    (MandatoryPhase *)array_get(child->mandatory_phases, i);

                error = +check_mandatory_phase(phase, info);
            }
        }
    }

    smap_t *attr_name = smap_init(16);

    if (node->attrs) {
        for (int i = 0; i < array_size(node->attrs); i++) {
            Attr *attr = (Attr *)array_get(node->attrs, i);
            Attr *orig_attr;

            if ((orig_attr = smap_retrieve(attr_name, attr->id)) != NULL) {
                print_error(attr->id,
                            "Duplicate name '%s' in atributes of node '%s'",
                            attr->id, node->id);
                print_note(orig_attr->id, "Previously declared here");
                error = 1;
            } else {
                smap_insert(attr_name, attr->id, attr);
            }

            if (attr->type == AT_link_or_enum) {
                Node *attr_node =
                    (Node *)smap_retrieve(info->node_name, attr->type_id);
                Enum *attr_enum =
                    (Enum *)smap_retrieve(info->enum_name, attr->type_id);

                if (attr_node) {
                    attr->type = AT_link;
                } else if (attr_enum) {
                    attr->type = AT_enum;
                } else {
                    print_error(
                        attr->type_id,
                        "Unknown type '%s' of attribute '%s' of node '%s'",
                        attr->type_id, attr->id, node->id);
                    error = 1;
                }
            }
        }
    }

    smap_free(child_name);
    smap_free(attr_name);

    return error;
}

static int check_nodeset(Nodeset *nodeset, struct Info *info) {
    int error = 0;

    smap_t *node_name = smap_init(16);

    for (int i = 0; i < array_size(nodeset->nodes); ++i) {
        char *node = (char *)array_get(nodeset->nodes, i);
        char *orig_node;

        // Check if there is no duplicate naming.
        if ((orig_node = smap_retrieve(node_name, node)) != NULL) {
            print_error(node, "Duplicate name '%s' in nodes of nodeset '%s'",
                        node, nodeset->id);
            print_note(orig_node, "Previously declared here");
            error = 1;
        } else {
            smap_insert(node_name, node, node);
        }

        Node *nodeset_node = (Node *)smap_retrieve(info->node_name, node);

        Nodeset *nodeset_nodeset =
            (Nodeset *)smap_retrieve(info->nodeset_name, node);

        if (nodeset_nodeset) {
            print_error(node, "Nodeset '%s' contains other nodeset '%s'",
                        nodeset->id, nodeset_nodeset->id);
            error = 1;
        } else if (!nodeset_node) {
            print_error(node, "Unknown type of node '%s' in nodeset '%s'",
                        node, nodeset->id);
            error = 1;
        } else {
            mem_free(node);
            array_set(nodeset->nodes, i, nodeset_node);
        }
    }

    smap_free(node_name);

    return error;
}

static int check_enum(Enum *arg_enum, struct Info *info) {

    int error = 0;
    smap_t *value_name = smap_init(16);

    for (int i = 0; i < array_size(arg_enum->values); ++i) {
        char *cur_value = (char *)array_get(arg_enum->values, i);
        char *orig_value;

        // Check if there is no duplicate naming.
        if ((orig_value = smap_retrieve(value_name, cur_value)) != NULL) {
            print_error(cur_value,
                        "Duplicate name '%s' in values of enum '%s'",
                        cur_value, arg_enum->id);
            print_note(orig_value, "Previously declared here");

            error = 1;
        } else {
            smap_insert(value_name, cur_value, cur_value);
        }
    }

    smap_free(value_name);
    return error;
}

static int check_traversal(Traversal *traversal, struct Info *info) {

    // TODO: check collission of func

    int error = 0;

    if (traversal->nodes == NULL)
        return 0;

    smap_t *node_name = smap_init(16);
    smap_t *node_name_expanded = smap_init(16);

    array *nodes_expanded = array_init(16);

    for (int i = 0; i < array_size(traversal->nodes); ++i) {
        char *node = (char *)array_get(traversal->nodes, i);
        char *orig_node;

        // Check if there is no duplicate naming.
        if ((orig_node = smap_retrieve(node_name, node)) != NULL) {
            print_error(node, "Duplicate name '%s' in nodes of traversal '%s'",
                        node, traversal->id);
            print_note(orig_node, "Previously declared here");
            error = 1;
        } else {
            smap_insert(node_name, node, node);
        }

        Node *traversal_node = (Node *)smap_retrieve(info->node_name, node);
        Nodeset *traversal_nodeset =
            (Nodeset *)smap_retrieve(info->nodeset_name, node);

        if (traversal_node) {
            array_append(nodes_expanded, strdup(node));
            smap_insert(node_name_expanded, node, node);
        } else if (traversal_nodeset) {

            // Add every node in the nodeset to the expanded node list
            for (int j = 0; j < array_size(traversal_nodeset->nodes); j++) {
                Node *nodeset_node = array_get(traversal_nodeset->nodes, j);
                if (smap_retrieve(node_name_expanded, nodeset_node->id) ==
                    NULL) {
                    array_append(nodes_expanded, strdup(nodeset_node->id));
                    smap_insert(node_name_expanded, nodeset_node->id,
                                nodeset_node);
                }
            }
        } else {
            print_error(
                node, "Unknown type of node or nodeset '%s' in traversal '%s'",
                node, traversal->id);
            error = 1;
        }
    }

    array_cleanup(traversal->nodes, mem_free);
    traversal->nodes = nodes_expanded;

    smap_free(node_name);
    smap_free(node_name_expanded);

    return error;
}

static int check_pass(Pass *pass, struct Info *info) {

    int error = 0;

    // TODO: check collission of func

    return error;
}

static int check_action_reference(Action *action, struct Info *info) {
    char *ref = (char *)action->action;
    void *item = smap_retrieve(info->phase_name, ref);
    if (item != NULL) {
        Phase *p = (Phase *)item;
        action->type = ACTION_PHASE;
        action->action = p;
        mem_free(ref);
        return 0;
    }

    item = smap_retrieve(info->traversal_name, ref);
    if (item != NULL) {
        action->type = ACTION_TRAVERSAL;
        action->action = item;
        mem_free(ref);
        return 0;
    }

    item = smap_retrieve(info->pass_name, ref);
    if (item != NULL) {
        action->type = ACTION_PASS;
        action->action = item;
        mem_free(ref);
        return 0;
    }

    print_error(
        action->action,
        "ID is not a reference to a defined pass, traversal or phase.");
    return 1;
}

static int check_action_phase(Action *action, struct Info *info) {
    Phase *phase = (Phase *)action->action;
    Phase *original = smap_retrieve(info->phase_name, phase->id);
    if (original != NULL) {
        print_error(phase->id, "Redefinition of name '%s'", phase->id);
        print_note(original->id, "Previously declared here");
        return 1;
    }
    array_append(info->config->phases, phase);
    smap_insert(info->phase_name, phase->id, phase);
    return 0;
}

static int check_action_pass(Action *action, struct Info *info) {
    Pass *pass = action->action;
    Pass *original = smap_retrieve(info->pass_name, pass->id);
    if (original != NULL) {
        print_error(pass->id, "Redefinition of name '%s'", pass->id);
        print_note(original->id, "Previously declared here");
        return 1;
    }
    array_append(info->config->passes, pass);
    smap_insert(info->pass_name, pass->id, pass);
    return 0;
}

static int check_action_traversal(Action *action, struct Info *info) {
    Traversal *trav = action->action;
    Traversal *original = smap_retrieve(info->traversal_name, trav->id);
    if (original != NULL) {
        print_error(trav->id, "Redefinion of traversal '%s'", trav->id);
        print_note(original->id, "Previously defined here");
        return 1;
    }
    array_append(info->config->traversals, trav);
    smap_insert(info->traversal_name, trav->id, trav);
    return 0;
}

static int check_action(Action *action, struct Info *info) {
    switch (action->type) {
    case ACTION_REFERENCE:
        return check_action_reference(action, info);
    case ACTION_PHASE:
        return check_action_phase(action, info);
    case ACTION_PASS:
        return check_action_pass(action, info);
    case ACTION_TRAVERSAL:
        return check_action_traversal(action, info);
    default:
        return 1;
    }
}

static int check_actions(array *actions, struct Info *info) {
    int error = 0;
    for (int i = 0; i < array_size(actions); i++) {
        Action *action = array_get(actions, i);
        error = check_action(action, info) != 0 ? 1 : error;
    }

    return error;
}

static inline void add_required_root_to_phase(Phase *phase, char *root) {
    ccn_set_insert(phase->roots, ccn_str_cpy(root));
}

static int check_phase(Phase *phase, struct Info *info, smap_t *phase_order) {
    int error = 0;

    if (phase->start) {
        if (info->root_phase != NULL) { // TODO: renamte root_phase to start_phase in info struct.
            print_error(phase->id, "Double declaration of start phase");
            print_note(info->root_phase->id, "Previously declared here");
            error = 1;
        } else {
            info->root_phase = phase;
        }
    }



    for (int i = 0; i < array_size(phase->actions); ++i) {
        Action *action = array_get(phase->actions, i);
        error = check_action(action, info) != 0 ? 1 : error;
        if (action->type == ACTION_PHASE && phase->root != NULL) {
            add_required_root_to_phase((Phase *)action->action, phase->root);
        }

    }
    smap_insert(phase_order, phase->id, phase);

    return error;
}

// TODO: handle cyclic dependencies. IF A depends on B and B on A this will go
// on forever.... Need to throw an error then.
static void evaluate_set_expr(SetExpr *expr, struct Info *info, int *error) {
    CCNset_t *new_set = NULL;
    if (expr->type == SET_REFERENCE) {
        Nodeset *target = smap_retrieve(info->nodeset_name, expr->ref_id);
        evaluate_set_expr(target->expr, info, error);

        assert(target->expr->type == SET_LITERAL);

        new_set = ccn_set_copy(target->expr->id_set);

        mem_free(expr->ref_id);
        expr->type = SET_LITERAL;
        expr->id_set = new_set;
    } else if (expr->type == SET_OPERATION) {
        evaluate_set_expr(expr->operation->left_child, info, error);
        evaluate_set_expr(expr->operation->right_child, info, error);
        CCNset_t *left = expr->operation->left_child->id_set;
        CCNset_t *right = expr->operation->right_child->id_set;

        switch (expr->operation->operator) {
        case SET_UNION:
            new_set = ccn_set_union(left, right);
            break;
        case SET_INTERSECT:
            new_set = ccn_set_intersect(left, right);
            break;
        case SET_DIFFERENCE:
            new_set = ccn_set_difference(left, right);
            break;
        default: // TODO throw unsupported error.
            break;
        }
        free_setOperation(expr->operation);
        expr->type = SET_LITERAL;
        expr->id_set = new_set;
    } else if (expr->type == SET_LITERAL) {
        assert(expr->id_set != NULL);
    }
}

static array *set_to_array(CCNset_t *set) {
    assert(set != NULL);
    array *values = smap_values(set->hash_map);
    smap_free(set->hash_map);
    mem_free(set);
    return values;
}

static int evaluate_nodesets_expr(array *nodesets, struct Info *info) {
    int error = 0;

    for (int i = 0; i < array_size(nodesets); ++i) {
        Nodeset *nodeset = (Nodeset *)array_get(nodesets, i);
        evaluate_set_expr(nodeset->expr, info, &error);
    }

    return error;
}

static int evaluate_traversals_expr(array *traversals, struct Info *info) {
    int error = 0;
    for (int i = 0; i < array_size(traversals); i++) {
        Traversal *trav = (Traversal *)array_get(traversals, i);
        if (trav->expr == NULL)
            continue;
        evaluate_set_expr(trav->expr, info, &error);
    }

    return error;
}

static int nodesets_expr_to_array(array *nodesets, struct Info *info) {
    int error = 0;

    for (int i = 0; i < array_size(nodesets); ++i) {
        Nodeset *nodeset = (Nodeset *)array_get(nodesets, i);
        if (nodeset->expr->type != SET_LITERAL)
            continue;
        array *nodes = set_to_array(nodeset->expr->id_set);
        nodeset->expr->id_set = NULL;
        free_setExpr(nodeset->expr);
        nodeset->nodes = nodes;
    }

    return error;
}

static int traversals_expr_to_array(array *traversals, struct Info *info) {
    int error = 0;

    for (int i = 0; i < array_size(traversals); ++i) {
        Traversal *trav = (Traversal *)array_get(traversals, i);
        if (trav->expr == NULL)
            continue;
        array *nodes = set_to_array(trav->expr->id_set);
        trav->expr->id_set = NULL;
        free_setExpr(trav->expr);
        trav->nodes = nodes;
    }

    return error;
}

int check_config(Config *config) {

    int success = 0;
    struct Info *info = create_info(config);
    smap_t *phase_order = smap_init(16);
    Phase *cur_phase;
    bool start_phase_seen = false;
    bool phase_errors = false;

    success += check_nodes(config->nodes, info);
    success += check_nodesets(config->nodesets, info);
    success += check_enums(config->enums, info);

    if (info->root_node == NULL) {
        print_error_no_loc("No root node specified.");
        success++;
    } else {
        config->root_node = info->root_node;
    }

    //generate_sub_root_traversals(config);
    success += check_traversals(config->traversals, info);
    success += check_passes(config->passes, info);
    success += check_phases(config->phases, info);

    subtree_generate_traversals(config);

    // Transform setExpr to array of node ptrs.
    success += evaluate_nodesets_expr(config->nodesets, info);
    success += evaluate_traversals_expr(config->traversals, info);

    // Transform all nodeset expressions to arrays.
    success += nodesets_expr_to_array(config->nodesets, info);
    success += traversals_expr_to_array(config->traversals, info);

    // From here all SetExprs for nodes are transformed into arrays.

    for (int i = 0; i < array_size(config->nodes); ++i) {
        success += check_node(array_get(config->nodes, i), info);
    }

    for (int i = 0; i < array_size(config->nodesets); ++i) {
        success += check_nodeset(array_get(config->nodesets, i), info);
    }

    for (int i = 0; i < array_size(config->enums); ++i) {
        success += check_enum(array_get(config->enums, i), info);
    }

    for (int i = 0; i < array_size(config->traversals); ++i) {
        success += check_traversal(array_get(config->traversals, i), info);
    }
    for (int i = 0; i < array_size(config->passes); ++i) {
        success += check_pass(array_get(config->passes, i), info);
    }

    for (int i = 0; i < array_size(config->phases); ++i) {
        cur_phase = array_get(config->phases, i);

        if (cur_phase->start)
            start_phase_seen = true;

        int res = check_phase(cur_phase, info, phase_order);
        success += res;
        if (res)
            phase_errors = true;
    }



    if (info->root_phase == NULL) {
        print_error_no_loc("No start phase specified.");
        success++;
    }

    smap_free(phase_order);
    free_info(info);

    return success;
}
