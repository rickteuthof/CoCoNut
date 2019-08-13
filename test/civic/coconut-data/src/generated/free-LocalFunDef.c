// Hash: 335492ed82f8520c39ccbce6a5739af7
#include "generated/free-LocalFunDef.h"

#include "generated/free-FunDef.h"
#include "generated/free-LocalFunDef.h"
void free_LocalFunDef_tree(struct LocalFunDef* node) {
    if (node == NULL) {
        return;
    }

    free_FunDef_tree(node->decl);
    free_LocalFunDef_tree(node->next);
    mem_free(node);
}
void free_LocalFunDef_node(struct LocalFunDef* node) {
 // skip children.
    mem_free(node);
}

