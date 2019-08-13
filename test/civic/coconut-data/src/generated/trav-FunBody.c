// Hash: b749bf704b901788bcd7cb60caea2822
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FunBody.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_LocalFunDef(struct LocalFunDef *node, struct Info *info);
void _CCNtrav_StmtList(struct StmtList *node, struct Info *info);
void _CCNtrav_VarDec(struct VarDec *node, struct Info *info);

void CCNtrav_FunBody_localfundef(FunBody *node, struct Info *info) {
    node->localfundef = _CCNtrav_LocalFunDef(node->localfundef, info);
}

void CCNtrav_FunBody_stmtlist(FunBody *node, struct Info *info) {
    node->stmtlist = _CCNtrav_StmtList(node->stmtlist, info);
}

void CCNtrav_FunBody_vardec(FunBody *node, struct Info *info) {
    node->vardec = _CCNtrav_VarDec(node->vardec, info);
}

FunBody *_CCNtrav_FunBody(FunBody *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_SplitInit:
        return SplitInit_FunBody(node, info);;
    case TRAV_Symbols:
        CCNtrav_FunBody_localfundef(node, info);
        break;
    case TRAV_TypeCheck:
        return TypeCheck_FunBody(node, info);;
    default:
        CCNtrav_FunBody_localfundef(node, info);
        CCNtrav_FunBody_stmtlist(node, info);
        CCNtrav_FunBody_vardec(node, info);
        break;
    }
    return node;
}

void replace_FunBody(struct FunBody *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FunBody;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FunBody: Not making a node replacement, since another replacement function was already called previously.");
    }
}

