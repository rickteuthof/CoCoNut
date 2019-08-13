// Hash: da1486863569ad210a4555708de59ea2
#include "generated/free-Decls.h"

#include "generated/free-Decl.h"
#include "generated/free-Decls.h"
void free_Decls_tree(struct Decls* node) {
    if (node == NULL) {
        return;
    }

    free_Decl_tree(node->decl);
    free_Decls_tree(node->next);
    mem_free(node);
}
void free_Decls_node(struct Decls* node) {
 // skip children.
    mem_free(node);
}

