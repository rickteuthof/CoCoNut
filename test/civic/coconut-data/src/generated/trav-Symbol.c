// Hash: 2a17d582c98658539abe0f791e2036ae
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Symbol.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_Symbol(struct Symbol *node, struct Info *info);

void CCNtrav_Symbol_next(Symbol *node, struct Info *info) {
    node->next = _CCNtrav_Symbol(node->next, info);
}

Symbol *_CCNtrav_Symbol(Symbol *node, struct Info *info) {
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
        return Symbols_Symbol(node, info);;
    case TRAV_TypeCheck:
        break;
    default:
        CCNtrav_Symbol_next(node, info);
        break;
    }
    return node;
}

void replace_Symbol(struct Symbol *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Symbol;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Symbol: Not making a node replacement, since another replacement function was already called previously.");
    }
}

