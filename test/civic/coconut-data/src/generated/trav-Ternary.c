// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Ternary.h"
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
void _CCNtrav_BinOp(struct BinOp *node, struct Info *info);
void _CCNtrav_BoolConst(struct BoolConst *node, struct Info *info);
void _CCNtrav_Cast(struct Cast *node, struct Info *info);
void _CCNtrav_FloatConst(struct FloatConst *node, struct Info *info);
void _CCNtrav_FunCall(struct FunCall *node, struct Info *info);
void _CCNtrav_IntConst(struct IntConst *node, struct Info *info);
void _CCNtrav_MonOp(struct MonOp *node, struct Info *info);
void _CCNtrav_Ternary(struct Ternary *node, struct Info *info);
void _CCNtrav_Var(struct Var *node, struct Info *info);

void CCNtrav_Ternary_falseexpr(Ternary *node, struct Info *info) {
    node->falseexpr = _CCNtrav_Expr(node->falseexpr, info);
}

void CCNtrav_Ternary_testexpr(Ternary *node, struct Info *info) {
    node->testexpr = _CCNtrav_Expr(node->testexpr, info);
}

void CCNtrav_Ternary_trueexpr(Ternary *node, struct Info *info) {
    node->trueexpr = _CCNtrav_Expr(node->trueexpr, info);
}

Ternary *_CCNtrav_Ternary(Ternary *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    default:
        CCNtrav_Ternary_falseexpr(node, info);
        CCNtrav_Ternary_testexpr(node, info);
        CCNtrav_Ternary_trueexpr(node, info);
        break;
    }
    return node;
}

void replace_Ternary(struct Ternary *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Ternary;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Ternary: Not making a node replacement, since another replacement function was already called previously.");
    }
}

