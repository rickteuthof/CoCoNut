// Hash: 33e19f933fee95125167d08907d344d2
#include "generated/free-FunHeader.h"

#include "generated/free-Param.h"
void free_FunHeader_tree(struct FunHeader* node) {
    if (node == NULL) {
        return;
    }

    free_Param_tree(node->params);
    mem_free(node->id);
    mem_free(node);
}
void free_FunHeader_node(struct FunHeader* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

