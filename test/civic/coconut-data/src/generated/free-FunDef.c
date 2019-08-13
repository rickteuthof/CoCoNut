// Hash: 1e4fc8c57864026894e956f2ce63ce36
#include "generated/free-FunDef.h"

#include "generated/free-FunBody.h"
#include "generated/free-FunHeader.h"
#include "generated/free-FunSymbol.h"
#include "generated/free-FunDef.h"
#include "generated/free-Symbol.h"
void free_FunDef_tree(struct FunDef* node) {
    if (node == NULL) {
        return;
    }

    free_FunBody_tree(node->funbody);
    free_FunHeader_tree(node->funheader);
    free_FunSymbol_tree(node->funsymbol);
    free_FunDef_tree(node->next);
    free_Symbol_tree(node->symbol);
    mem_free(node);
}
void free_FunDef_node(struct FunDef* node) {
 // skip children.
    mem_free(node);
}

