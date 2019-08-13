// Hash: 4b5f0f88bdd5355115a58de9c899d7b4
#include "generated/free-Return.h"

#include "generated/free-Expr.h"
void free_Return_tree(struct Return* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    mem_free(node);
}
void free_Return_node(struct Return* node) {
 // skip children.
    mem_free(node);
}

