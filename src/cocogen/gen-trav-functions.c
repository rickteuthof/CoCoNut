#include "cocogen/ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/str-ast.h"
#include "lib/imap.h"
#include "lib/memory.h"
#include "lib/smap.h"
#include "lib/str.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Map from node name to index in reachability matrix
static smap_t *node_index = NULL;

// Node reachability matrix
static bool **node_reachability = NULL;

static bool **traversal_node_handles = NULL;

#define ERROR_HEADER "traversal-driver"

static void compute_reachable_nodes(Config *config) {
    if (node_reachability && traversal_node_handles) {
        return;
    }
    node_index = smap_init(32);

    size_t num_nodes = array_size(config->nodes);
    size_t num_nodesets = array_size(config->nodesets);

    // Add nodes to node_index map
    for (int i = 0; i < num_nodes; i++) {
        Node *node = array_get(config->nodes, i);
        int *index = mem_alloc(sizeof(int));
        *index = i;
        smap_insert(node_index, node->id, index);
    }

    for (int i = 0; i < num_nodesets; i++) {
        Nodeset *nodeset = array_get(config->nodesets, i);
        int *index = mem_alloc(sizeof(int));
        *index = i + num_nodes;
        smap_insert(node_index, nodeset->id, index);
    }

    // Allocate node reachability matrix

    size_t num_total = num_nodes + num_nodesets;

    node_reachability = mem_alloc(sizeof(bool *) * num_total);

    for (int i = 0; i < num_total; i++) {
        node_reachability[i] = mem_alloc(sizeof(bool) * num_total);
        memset(node_reachability[i], 0, sizeof(bool) * num_total);
    }

    // Initialise reachability matrix with adjacency matrix

    for (int i = 0; i < num_nodes; i++) {
        Node *node = array_get(config->nodes, i);

        for (int j = 0; j < array_size(node->children); j++) {
            Child *child = array_get(node->children, j);

            int *index = smap_retrieve(node_index, child->type);
            node_reachability[*index][i] = true;
        }
    }

    for (int i = 0; i < num_nodesets; i++) {
        Nodeset *nodeset = array_get(config->nodesets, i);

        for (int j = 0; j < array_size(nodeset->nodes); j++) {
            Node *node = array_get(nodeset->nodes, j);
            int *index = smap_retrieve(node_index, node->id);
            node_reachability[*index][num_nodes + i] = true;
        }
    }

    // Compute reachability of nodes using the Floyd-Warshall algorithm
    for (int k = 0; k < num_total; k++) {
        for (int i = 0; i < num_total; i++) {
            for (int j = 0; j < num_total; j++) {

                if (node_reachability[k][i] && node_reachability[j][k])
                    node_reachability[j][i] = true;
            }
        }
    }

    // Fill traversal_node_handles table

    size_t num_traversals = array_size(config->traversals);

    traversal_node_handles = mem_alloc(sizeof(bool *) * num_traversals);

    for (int i = 0; i < num_traversals; i++) {
        Traversal *traversal = array_get(config->traversals, i);

        traversal_node_handles[i] = mem_alloc(sizeof(bool) * num_total);

        // Traversal handles all nodes
        if (traversal->nodes == NULL) {
            for (int j = 0; j < num_total; j++) {
                traversal_node_handles[i][j] = true;
            }
        } else {
            memset(traversal_node_handles[i], 0, sizeof(bool) * num_total);

            for (int j = 0; j < array_size(traversal->nodes); j++) {
                char *node_name = array_get(traversal->nodes, j);
                int *index = smap_retrieve(node_index, node_name);

                // List of nodes from where the handled node can be reached
                bool *reach_nodes = node_reachability[*index];

                // Add the handled node itself to the list of nodes that need
                // to be traversed
                traversal_node_handles[i][*index] = true;

                // Add the nodes in reach_node
                for (int k = 0; k < num_total; k++) {
                    if (reach_nodes[k])
                        traversal_node_handles[i][k] = true;
                }
            }
        }
    }
}


void generate_nodeset_traversals_source(Config *config, FILE *fp) {
    int indent = 0;

    for (int i = 0; i < array_size(config->nodesets); i++) {
        Nodeset *nodeset = array_get(config->nodesets, i);
        out_start_func(NODE_TYPE " *_" TRAV_PREFIX "%s(%s *node, struct Info *info)", nodeset->id, nodeset->id, nodeset->id);

        out_end_func();
    }
}


void generate_start_helper_functions_definitions(Config *config, FILE *fp)
{
    int indent = 0;

    out_statement("struct Info *_CCNmakeInfoStruct(" TRAV_ENUM_NAME " trav_type)");
    out_statement("void _CCNdestroyInfoStruct(" TRAV_ENUM_NAME " trav_type, struct Info *info)");
}


void generate_start_helper_functions_source(Config *config, FILE *fp)
{
    int indent = 0;

    out_start_func("struct Info *_CCNmakeInfoStruct(" TRAV_ENUM_NAME " trav_type)");
    out_begin_switch("trav_type");
    for (int i = 0; i < array_size(config->traversals); i++) {
        Traversal *trav = array_get(config->traversals, i);
        out_begin_case(TRAV_FORMAT, trav->id);
        out_statement("return %s_createinfo()", trav->id);
        out_end_case();
    } 
    out_end_switch();
    out_end_func();

    out_start_func("void _CCNdestroyInfoStruct(" TRAV_ENUM_NAME " trav_type, struct Info *info)");
    out_begin_switch("trav_type");
    for (int i = 0; i < array_size(config->traversals); i++) {
        Traversal *trav = array_get(config->traversals, i);
        out_begin_case(TRAV_FORMAT, trav->id);
        out_statement("return %s_freeinfo()", trav->id);
        out_end_case();
    } 
    out_end_switch();
    out_end_func();
}

static void generate_start_node(Config *config, FILE *fp, bool is_header_file,
                                Node *node) 
{
    int indent = 0;
    if (node->root) {
        if (is_header_file) {
            out_statement("%s *" TRAV_PREFIX "start_%s(%s *node, " TRAV_ENUM_NAME " trav_type)", node->id, node->id, node->id);
        } else {
            generate_start_helper_functions_definitions(config, fp);
            out("\n");
            out_start_func("%s *" TRAV_START_FORMAT "(%s *node, " TRAV_ENUM_NAME " trav_type)", node->id, node->id, node->id);
            out_statement("struct Info *info = _CCNmakeInfoStruct(trav_type)");
            out_statement("node = _" TRAV_PREFIX "%s(node, info)", node->id);
            out_statement("_CCNdestroyInfoStruct(" TRAV_ENUM_NAME " trav_type, struct Info *info)");
            out_statement("return node");
            out_end_func();
        }
    }
}

static void generate_node_child_node(Node *node, Child *child, FILE *fp) {
    out("    _" TRAV_PREFIX "%s(node->%s, info);\n", child->type, child->id);

    out("    if (node_replacement != NULL) {\n");
    out("        if (node_replacement_type == " NT_FORMAT ") {\n",
        child->type);
    out("            node->%s = node_replacement;\n", child->id);
    out("        } else {\n");
    out("            print_user_error(\"" ERROR_HEADER
        "\",  \"Replacement node for %s->%s is not of "
        "type "
        "%s.\");\n",
        node->id, child->id, child->type);
    out("        }\n");
    out("    }\n");
}

static void generate_node_child_nodeset(Node *node, Child *child, FILE *fp) {
    out("    if (!node->%s) return;\n", child->id);
    out("    switch (node->%s->type) {\n", child->id);

    Nodeset *nodeset = child->nodeset;

    for (int i = 0; i < array_size(nodeset->nodes); ++i) {
        Node *cnode = (Node *)array_get(nodeset->nodes, i);
        out("    case " NS_FORMAT ":\n", nodeset->id, cnode->id);
        out("        _" TRAV_PREFIX "%s(node->%s->value.val_%s, info);\n",
            cnode->id, child->id, cnode->id);
        out("        break;\n");
    }

    out("    }\n\n");

    out("    if (node_replacement != NULL) {\n");

    out("        switch (node_replacement_type) {\n");
    for (int i = 0; i < array_size(nodeset->nodes); ++i) {
        Node *cnode = (Node *)array_get(nodeset->nodes, i);
        out("        case " NT_FORMAT ":\n", cnode->id);
        out("            node->%s->value.val_%s = node_replacement;\n",
            child->id, cnode->id);
        out("            node->%s->type = " NS_FORMAT ";\n", child->id,
            child->type, cnode->id);
        out("            break;\n");
    }

    out("        default:\n");
    out("            print_user_error(\"" ERROR_HEADER
        "\", \"Replacement node for %s->%s is not a "
        "node type of nodeset %s.\");\n",
        node->id, child->id, child->type);
    out("            break;\n");
    out("        }\n");

    out("    }\n");
}

/* Checks whether a traversal handles a node, so if a user
 * defined function needs to be called.
 */
static bool traversalHandlesNode(Node *node, Traversal *trav)
{
    for (int i = 0; i < array_size(trav->nodes); i++) {
        char *node_id = array_get(trav->nodes, i);
        if (ccn_str_equal(node->id, node_id)) {
            return true;
        }
    }
    return false;
}

static bool traversalCanReachChild(int trav_index, Child *child)
{
    int *index = smap_retrieve(node_index, child->type);
    return traversal_node_handles[trav_index][*index];
}

static bool traversalCanReachAllChildren(int trav_index, Node *target)
{
    for (int i = 0; i < array_size(target->children); ++i) {
        Child *child = array_get(target->children, i);
        if (!traversalCanReachChild(trav_index, child)) {
            return false;
        }
    }

    return true;
}

static void generate_trav_node(Node *node, FILE *fp, Config *config,
                               bool is_header_file) 
{
    int indent = 0;        
    if (!is_header_file) {
        for(int i = 0; i < array_size(node->children); i++) {
            Child *child = array_get(node->children, i);
            out_start_func("void " TRAV_PREFIX "%s_%s(%s *node, struct Info *info)", node->id, child->id, node->id);
            out_statement("node->%s = _" TRAV_PREFIX "%s(node->%s, info)", child->id, child->type, child->id);
            out_end_func();
        }

        out_start_func("%s *_" TRAV_PREFIX "%s(%s *node, struct Info *info)", node->id, node->id, node->id);
        out_statement("if (!node) return node");

        out_begin_switch(TRAV_PREFIX "current())");
        for (int i = 0; i < array_size(config->traversals); i++) {
            Traversal *trav = array_get(config->traversals, i);
            if (traversalHandlesNode(node, trav)) {
                out_begin_case(TRAV_FORMAT, trav->id);
                out_statement("return " TRAVERSAL_HANDLER_FORMAT "(node, info);", trav->id, node->id);
                out_end_case();
            } else {
                // This will be handled by the default case, will reduce size of switch.
                if (traversalCanReachAllChildren(i, node)) {
                    continue;
                }
                out_begin_case(TRAV_FORMAT, trav->id);
                for (int j = 0; j < array_size(node->children); j++) {
                    Child *child = array_get(node->children, j);
                    if (traversalCanReachChild(i, child)) {
                        out_statement(TRAV_PREFIX "%s_%s(node, info)", node->id, child->id);
                    }
                }
                out_statement("break");
                out_end_case();
            }
        }
        out_begin_default_case();
        for (int i = 0; i < array_size(node->children); i++) {
            Child *child = array_get(node->children, i);
            out_statement(TRAV_PREFIX "%s_%s(node, info)", node->id, child->id);
        }
        out_statement("break");
        out_end_case();
        out_end_switch();
        out_statement("return node");
        out_end_func();
    }
}

void generate_trav_header(Config *config, FILE *fp) {
    for (int i = 0; i < array_size(config->nodes); i++) {
        Node *node = array_get(config->nodes, i);
        out("#include \"generated/trav-%s.h\"\n", node->id);
    }
}


void generate_trav_node_header(Config *config, FILE *fp, Node *node) {
    compute_reachable_nodes(config);
    out("#pragma once\n");
    out("#include \"generated/trav-core.h\"\n");

    out("struct Info;\n");

    generate_trav_node(node, fp, config, true);
    generate_start_node(config, fp, true, node);
}

void generate_trav_node_definitions(Config *config, FILE *fp, Node *node) {
    compute_reachable_nodes(config);
    int indent = 0;

    out("#include <stdio.h>\n");
    out("#include \"lib/print.h\"\n");
    out("#include \"generated/trav-%s.h\"\n", node->id);
    out("// generated/trav-core.h is included by my header.\n");

    out_statement("extern struct Info");
    out("\n");

    for (int i = 0; i < array_size(node->children); i++) {
        Child *child = array_get(node->children, i);

        if (child->node) {
            out("void _" TRAV_PREFIX
                "%s(struct %s *node, struct Info *info);\n",
                child->type, child->type);
        } else if (child->nodeset) {
            for (int j = 0; j < array_size(child->nodeset->nodes); j++) {
                Node *nodechild = array_get(child->nodeset->nodes, j);
                out("void _" TRAV_PREFIX
                    "%s(struct %s *node, struct Info *info);\n",
                    nodechild->id, nodechild->id);
            }
        }
    }
    out("\n");

    generate_trav_node(node, fp, config, false);
    generate_start_node(config, fp, false, node);
}
