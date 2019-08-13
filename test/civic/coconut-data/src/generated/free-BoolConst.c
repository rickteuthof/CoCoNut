// Hash: 657816c98ab8bae4509f890a4cf4b654
#include "generated/free-BoolConst.h"

void free_BoolConst_tree(struct BoolConst* node) {
    if (node == NULL) {
        return;
    }

    mem_free(node);
}
void free_BoolConst_node(struct BoolConst* node) {
 // skip children.
    mem_free(node);
}

