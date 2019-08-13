// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#include "generated/free-IfElse.h"

#include "generated/free-Expr.h"
#include "generated/free-StmtList.h"
void free_IfElse_tree(struct IfElse* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->condition);
    free_StmtList_tree(node->elseblock);
    free_StmtList_tree(node->ifblock);
    mem_free(node);
}
void free_IfElse_node(struct IfElse* node) {
 // skip children.
    mem_free(node);
}

