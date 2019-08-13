// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-DoWhile.h"
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

void CCNtrav_DoWhile_block(DoWhile *node, struct Info *info) {
    node->block = _CCNtrav_StmtList(node->block, info);
}

void CCNtrav_DoWhile_condition(DoWhile *node, struct Info *info) {
    node->condition = _CCNtrav_Expr(node->condition, info);
}

DoWhile *_CCNtrav_DoWhile(DoWhile *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_DoWhile(node, info);;
    default:
        CCNtrav_DoWhile_block(node, info);
        CCNtrav_DoWhile_condition(node, info);
        break;
    }
    return node;
}

void replace_DoWhile(struct DoWhile *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_DoWhile;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_DoWhile: Not making a node replacement, since another replacement function was already called previously.");
    }
}

