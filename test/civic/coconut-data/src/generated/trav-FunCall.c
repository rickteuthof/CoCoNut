// Hash: cc2abd438fff2facf1c543ad95507122
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FunCall.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_ExprList(struct ExprList *node, struct Info *info);

void CCNtrav_FunCall_params(FunCall *node, struct Info *info) {
    node->params = _CCNtrav_ExprList(node->params, info);
}

FunCall *_CCNtrav_FunCall(FunCall *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_FunCall(node, info);;
    case TRAV_Refactor:
        return Refactor_FunCall(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_FunCall(node, info);;
    default:
        CCNtrav_FunCall_params(node, info);
        break;
    }
    return node;
}

void replace_FunCall(struct FunCall *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FunCall;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FunCall: Not making a node replacement, since another replacement function was already called previously.");
    }
}

