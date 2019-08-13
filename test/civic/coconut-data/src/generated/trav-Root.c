// Hash: 70eba40e9dab0c2491717f2637a08068
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Root.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_Decls(struct Decls *node, struct Info *info);
void _CCNtrav_FunSymbol(struct FunSymbol *node, struct Info *info);
void _CCNtrav_Symbol(struct Symbol *node, struct Info *info);

void CCNtrav_Root_decls(Root *node, struct Info *info) {
    node->decls = _CCNtrav_Decls(node->decls, info);
}

void CCNtrav_Root_funsymbol(Root *node, struct Info *info) {
    node->funsymbol = _CCNtrav_FunSymbol(node->funsymbol, info);
}

void CCNtrav_Root_symbol(Root *node, struct Info *info) {
    node->symbol = _CCNtrav_Symbol(node->symbol, info);
}

Root *_CCNtrav_Root(Root *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_Root(node, info);;
    case TRAV_Refactor:
        CCNtrav_Root_decls(node, info);
        break;
    case TRAV_RenameFor:
        CCNtrav_Root_decls(node, info);
        break;
    case TRAV_SplitInit:
        return SplitInit_Root(node, info);;
    case TRAV_Symbols:
        return Symbols_Root(node, info);;
    case TRAV_TypeCheck:
        CCNtrav_Root_decls(node, info);
        break;
    default:
        CCNtrav_Root_decls(node, info);
        CCNtrav_Root_funsymbol(node, info);
        CCNtrav_Root_symbol(node, info);
        break;
    }
    return node;
}

struct Info *_CCNmakeInfoStruct(TraversalType trav_type);
void _CCNdestroyInfoStruct(TraversalType trav_type, struct Info *info);

Root *CCNtrav_start_Root(Root *node, TraversalType trav_type) {
    struct Info *info = _CCNmakeInfoStruct(trav_type);
    node = _CCNtrav_Root(node, info);
    _CCNdestroyInfoStruct(TraversalType trav_type, struct Info *info);
}

void replace_Root(struct Root *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Root;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Root: Not making a node replacement, since another replacement function was already called previously.");
    }
}

