// Hash: e88afa1e610a0d88acf5ce24ec97f504
#include "generated/free-IntConst.h"

void free_IntConst_tree(struct IntConst* node) {
    if (node == NULL) {
        return;
    }

    mem_free(node);
}
void free_IntConst_node(struct IntConst* node) {
 // skip children.
    mem_free(node);
}

