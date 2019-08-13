// Hash: 70eba40e9dab0c2491717f2637a08068
#include "generated/free-Root.h"

#include "generated/free-Decls.h"
#include "generated/free-FunSymbol.h"
#include "generated/free-Symbol.h"
void free_Root_tree(struct Root* node) {
    if (node == NULL) {
        return;
    }

    free_Decls_tree(node->decls);
    free_FunSymbol_tree(node->funsymbol);
    free_Symbol_tree(node->symbol);
    mem_free(node);
}
void free_Root_node(struct Root* node) {
 // skip children.
    mem_free(node);
}

