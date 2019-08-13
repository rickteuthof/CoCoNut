// Hash: c25846fd3a15b982bb7497256c83a575
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FunSymbol.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_FunSymbol(struct FunSymbol *node, struct Info *info);

void CCNtrav_FunSymbol_next(FunSymbol *node, struct Info *info) {
    node->next = _CCNtrav_FunSymbol(node->next, info);
}

FunSymbol *_CCNtrav_FunSymbol(FunSymbol *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        break;
    case TRAV_Refactor:
        break;
    case TRAV_RenameFor:
        break;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        return Symbols_FunSymbol(node, info);;
    case TRAV_TypeCheck:
        break;
    default:
        CCNtrav_FunSymbol_next(node, info);
        break;
    }
    return node;
}

void replace_FunSymbol(struct FunSymbol *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FunSymbol;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FunSymbol: Not making a node replacement, since another replacement function was already called previously.");
    }
}

