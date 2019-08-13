// Hash: 2a17d582c98658539abe0f791e2036ae
#include "generated/free-Symbol.h"

#include "generated/free-Symbol.h"
void free_Symbol_tree(struct Symbol* node) {
    if (node == NULL) {
        return;
    }

    free_Symbol_tree(node->next);
    mem_free(node->name);
    mem_free(node);
}
void free_Symbol_node(struct Symbol* node) {
 // skip children.
    mem_free(node->name);
    mem_free(node);
}

