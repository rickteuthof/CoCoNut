// Hash: d370e4383f7aab78470bbb20eac500e8
#include "generated/free-GlobalDec.h"

void free_GlobalDec_tree(struct GlobalDec* node) {
    if (node == NULL) {
        return;
    }

    mem_free(node->id);
    mem_free(node);
}
void free_GlobalDec_node(struct GlobalDec* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

