// Hash: 0624d4152c0617b22ca17c7560e5b107
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-ExprList.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_BinOp(struct BinOp *node, struct Info *info);
void _CCNtrav_BoolConst(struct BoolConst *node, struct Info *info);
void _CCNtrav_Cast(struct Cast *node, struct Info *info);
void _CCNtrav_FloatConst(struct FloatConst *node, struct Info *info);
void _CCNtrav_FunCall(struct FunCall *node, struct Info *info);
void _CCNtrav_IntConst(struct IntConst *node, struct Info *info);
void _CCNtrav_MonOp(struct MonOp *node, struct Info *info);
void _CCNtrav_Ternary(struct Ternary *node, struct Info *info);
void _CCNtrav_Var(struct Var *node, struct Info *info);
void _CCNtrav_ExprList(struct ExprList *node, struct Info *info);

void CCNtrav_ExprList_expr(ExprList *node, struct Info *info) {
    node->expr = _CCNtrav_Expr(node->expr, info);
}

void CCNtrav_ExprList_next(ExprList *node, struct Info *info) {
    node->next = _CCNtrav_ExprList(node->next, info);
}

ExprList *_CCNtrav_ExprList(ExprList *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    default:
        CCNtrav_ExprList_expr(node, info);
        CCNtrav_ExprList_next(node, info);
        break;
    }
    return node;
}

void replace_ExprList(struct ExprList *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_ExprList;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_ExprList: Not making a node replacement, since another replacement function was already called previously.");
    }
}

