// Hash: 121eeb949095a740dd78338f981bac61
#include "generated/free-Var.h"

void free_Var_tree(struct Var* node) {
    if (node == NULL) {
        return;
    }

    mem_free(node->id);
    mem_free(node);
}
void free_Var_node(struct Var* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

