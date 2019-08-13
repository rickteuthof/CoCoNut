// Hash: b0bfe9d720169c1396aafc91b36ae925
#include "generated/free-MonOp.h"

#include "generated/free-Expr.h"
void free_MonOp_tree(struct MonOp* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    mem_free(node);
}
void free_MonOp_node(struct MonOp* node) {
 // skip children.
    mem_free(node);
}

