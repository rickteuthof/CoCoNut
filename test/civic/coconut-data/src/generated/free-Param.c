// Hash: 31ba4afd09094183d749087a75279dea
#include "generated/free-Param.h"

#include "generated/free-Param.h"
void free_Param_tree(struct Param* node) {
    if (node == NULL) {
        return;
    }

    free_Param_tree(node->next);
    mem_free(node->id);
    mem_free(node);
}
void free_Param_node(struct Param* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

