// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#include "generated/free-GlobalDef.h"

#include "generated/free-Expr.h"
void free_GlobalDef_tree(struct GlobalDef* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    mem_free(node->id);
    mem_free(node);
}
void free_GlobalDef_node(struct GlobalDef* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

