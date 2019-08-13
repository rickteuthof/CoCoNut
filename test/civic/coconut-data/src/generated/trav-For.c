// Hash: 1b5e131a901dfeb50ab1b084b4472381
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-For.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_StmtList(struct StmtList *node, struct Info *info);
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

void CCNtrav_For_block(For *node, struct Info *info) {
    node->block = _CCNtrav_StmtList(node->block, info);
}

void CCNtrav_For_boundexpr(For *node, struct Info *info) {
    node->boundexpr = _CCNtrav_Expr(node->boundexpr, info);
}

void CCNtrav_For_initexpr(For *node, struct Info *info) {
    node->initexpr = _CCNtrav_Expr(node->initexpr, info);
}

void CCNtrav_For_stepexpr(For *node, struct Info *info) {
    node->stepexpr = _CCNtrav_Expr(node->stepexpr, info);
}

For *_CCNtrav_For(For *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_For(node, info);;
    case TRAV_RenameFor:
        return RenameFor_For(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_For(node, info);;
    default:
        CCNtrav_For_block(node, info);
        CCNtrav_For_boundexpr(node, info);
        CCNtrav_For_initexpr(node, info);
        CCNtrav_For_stepexpr(node, info);
        break;
    }
    return node;
}

void replace_For(struct For *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_For;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_For: Not making a node replacement, since another replacement function was already called previously.");
    }
}

