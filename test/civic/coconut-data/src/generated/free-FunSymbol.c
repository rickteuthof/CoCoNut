// Hash: c25846fd3a15b982bb7497256c83a575
#include "generated/free-FunSymbol.h"

#include "generated/free-FunSymbol.h"
void free_FunSymbol_tree(struct FunSymbol* node) {
    if (node == NULL) {
        return;
    }

    free_FunSymbol_tree(node->next);
    mem_free(node->name);
    mem_free(node->scopedname);
    mem_free(node);
}
void free_FunSymbol_node(struct FunSymbol* node) {
 // skip children.
    mem_free(node->name);
    mem_free(node->scopedname);
    mem_free(node);
}

