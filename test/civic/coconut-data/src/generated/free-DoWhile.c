// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
#include "generated/free-DoWhile.h"

#include "generated/free-StmtList.h"
#include "generated/free-Expr.h"
void free_DoWhile_tree(struct DoWhile* node) {
    if (node == NULL) {
        return;
    }

    free_StmtList_tree(node->block);
    free_Expr_tree(node->condition);
    mem_free(node);
}
void free_DoWhile_node(struct DoWhile* node) {
 // skip children.
    mem_free(node);
}

