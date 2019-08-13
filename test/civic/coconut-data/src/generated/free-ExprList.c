// Hash: 0624d4152c0617b22ca17c7560e5b107
#include "generated/free-ExprList.h"

#include "generated/free-Expr.h"
#include "generated/free-ExprList.h"
void free_ExprList_tree(struct ExprList* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    free_ExprList_tree(node->next);
    mem_free(node);
}
void free_ExprList_node(struct ExprList* node) {
 // skip children.
    mem_free(node);
}

