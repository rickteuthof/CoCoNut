// Hash: 1e4fc8c57864026894e956f2ce63ce36
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FunDef.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_FunBody(struct FunBody *node, struct Info *info);
void _CCNtrav_FunHeader(struct FunHeader *node, struct Info *info);
void _CCNtrav_FunSymbol(struct FunSymbol *node, struct Info *info);
void _CCNtrav_FunDef(struct FunDef *node, struct Info *info);
void _CCNtrav_Symbol(struct Symbol *node, struct Info *info);

void CCNtrav_FunDef_funbody(FunDef *node, struct Info *info) {
    node->funbody = _CCNtrav_FunBody(node->funbody, info);
}

void CCNtrav_FunDef_funheader(FunDef *node, struct Info *info) {
    node->funheader = _CCNtrav_FunHeader(node->funheader, info);
}

void CCNtrav_FunDef_funsymbol(FunDef *node, struct Info *info) {
    node->funsymbol = _CCNtrav_FunSymbol(node->funsymbol, info);
}

void CCNtrav_FunDef_next(FunDef *node, struct Info *info) {
    node->next = _CCNtrav_FunDef(node->next, info);
}

void CCNtrav_FunDef_symbol(FunDef *node, struct Info *info) {
    node->symbol = _CCNtrav_Symbol(node->symbol, info);
}

FunDef *_CCNtrav_FunDef(FunDef *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_FunDef(node, info);;
    case TRAV_Refactor:
        CCNtrav_FunDef_funbody(node, info);
        CCNtrav_FunDef_next(node, info);
        break;
    case TRAV_RenameFor:
        CCNtrav_FunDef_funbody(node, info);
        CCNtrav_FunDef_next(node, info);
        break;
    case TRAV_SplitInit:
        CCNtrav_FunDef_funbody(node, info);
        CCNtrav_FunDef_next(node, info);
        break;
    case TRAV_Symbols:
        return Symbols_FunDef(node, info);;
    case TRAV_TypeCheck:
        return TypeCheck_FunDef(node, info);;
    default:
        CCNtrav_FunDef_funbody(node, info);
        CCNtrav_FunDef_funheader(node, info);
        CCNtrav_FunDef_funsymbol(node, info);
        CCNtrav_FunDef_next(node, info);
        CCNtrav_FunDef_symbol(node, info);
        break;
    }
    return node;
}

void replace_FunDef(struct FunDef *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FunDef;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FunDef: Not making a node replacement, since another replacement function was already called previously.");
    }
}

