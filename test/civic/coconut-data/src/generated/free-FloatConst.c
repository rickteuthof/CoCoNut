// Hash: e53f745fb8225fc8c2f64b87c6517cb3
#include "generated/free-FloatConst.h"

void free_FloatConst_tree(struct FloatConst* node) {
    if (node == NULL) {
        return;
    }

    mem_free(node);
}
void free_FloatConst_node(struct FloatConst* node) {
 // skip children.
    mem_free(node);
}

