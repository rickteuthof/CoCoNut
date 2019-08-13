// Hash: 514d9d5eed2b7d56245866708d0e1d89
#include "generated/free-BinOp.h"

#include "generated/free-Expr.h"
void free_BinOp_tree(struct BinOp* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->left);
    free_Expr_tree(node->right);
    mem_free(node);
}
void free_BinOp_node(struct BinOp* node) {
 // skip children.
    mem_free(node);
}

