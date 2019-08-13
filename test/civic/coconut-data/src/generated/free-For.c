// Hash: 1b5e131a901dfeb50ab1b084b4472381
#include "generated/free-For.h"

#include "generated/free-StmtList.h"
#include "generated/free-Expr.h"
void free_For_tree(struct For* node) {
    if (node == NULL) {
        return;
    }

    free_StmtList_tree(node->block);
    free_Expr_tree(node->boundexpr);
    free_Expr_tree(node->initexpr);
    free_Expr_tree(node->stepexpr);
    mem_free(node->id);
    mem_free(node);
}
void free_For_node(struct For* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

