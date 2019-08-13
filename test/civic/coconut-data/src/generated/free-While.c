// Hash: df86d0e15495f375db62ae5bf23c0be7
#include "generated/free-While.h"

#include "generated/free-StmtList.h"
#include "generated/free-Expr.h"
void free_While_tree(struct While* node) {
    if (node == NULL) {
        return;
    }

    free_StmtList_tree(node->block);
    free_Expr_tree(node->condition);
    mem_free(node);
}
void free_While_node(struct While* node) {
 // skip children.
    mem_free(node);
}

