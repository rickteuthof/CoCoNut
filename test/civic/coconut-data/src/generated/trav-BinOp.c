// Hash: 514d9d5eed2b7d56245866708d0e1d89
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-BinOp.h"
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
void _CCNtrav_BinOp(struct BinOp *node, struct Info *info);
void _CCNtrav_BoolConst(struct BoolConst *node, struct Info *info);
void _CCNtrav_Cast(struct Cast *node, struct Info *info);
void _CCNtrav_FloatConst(struct FloatConst *node, struct Info *info);
void _CCNtrav_FunCall(struct FunCall *node, struct Info *info);
void _CCNtrav_IntConst(struct IntConst *node, struct Info *info);
void _CCNtrav_MonOp(struct MonOp *node, struct Info *info);
void _CCNtrav_Ternary(struct Ternary *node, struct Info *info);
void _CCNtrav_Var(struct Var *node, struct Info *info);

void CCNtrav_BinOp_left(BinOp *node, struct Info *info) {
    node->left = _CCNtrav_Expr(node->left, info);
}

void CCNtrav_BinOp_right(BinOp *node, struct Info *info) {
    node->right = _CCNtrav_Expr(node->right, info);
}

BinOp *_CCNtrav_BinOp(BinOp *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_BinOp(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_BinOp(node, info);;
    default:
        CCNtrav_BinOp_left(node, info);
        CCNtrav_BinOp_right(node, info);
        break;
    }
    return node;
}

void replace_BinOp(struct BinOp *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_BinOp;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_BinOp: Not making a node replacement, since another replacement function was already called previously.");
    }
}

