// Hash: 1fabc23d00d09394712ebc11a0e33a24
#include "generated/free-VarLet.h"

#include "generated/free-Expr.h"
void free_VarLet_tree(struct VarLet* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    mem_free(node->id);
    mem_free(node);
}
void free_VarLet_node(struct VarLet* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

