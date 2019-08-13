// Hash: b42c3d81e8cab965bf25d8b307a365f2
#include "generated/free-Cast.h"

#include "generated/free-Expr.h"
void free_Cast_tree(struct Cast* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->expr);
    mem_free(node);
}
void free_Cast_node(struct Cast* node) {
 // skip children.
    mem_free(node);
}

