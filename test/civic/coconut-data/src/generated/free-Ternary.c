// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#include "generated/free-Ternary.h"

#include "generated/free-Expr.h"
void free_Ternary_tree(struct Ternary* node) {
    if (node == NULL) {
        return;
    }

    free_Expr_tree(node->falseexpr);
    free_Expr_tree(node->testexpr);
    free_Expr_tree(node->trueexpr);
    mem_free(node);
}
void free_Ternary_node(struct Ternary* node) {
 // skip children.
    mem_free(node);
}

