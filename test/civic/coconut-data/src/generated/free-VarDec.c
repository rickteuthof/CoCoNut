// Hash: 3e39a0cd59728ac5797ddd72e5100164
#include "generated/free-VarDec.h"

#include "generated/free-Expr.h"
#include "generated/free-VarDec.h"
void free_VarDec_tree(struct VarDec* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    free_VarDec_tree(node->next);
    mem_free(node->id);
    mem_free(node);
}
void free_VarDec_node(struct VarDec* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

