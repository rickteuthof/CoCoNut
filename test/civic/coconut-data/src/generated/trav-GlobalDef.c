// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-GlobalDef.h"
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

void CCNtrav_GlobalDef_expr(GlobalDef *node, struct Info *info) {
    node->expr = _CCNtrav_Expr(node->expr, info);
}

GlobalDef *_CCNtrav_GlobalDef(GlobalDef *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_GlobalDef(node, info);;
    case TRAV_SplitInit:
        return SplitInit_GlobalDef(node, info);;
    case TRAV_Symbols:
        break;
    default:
        CCNtrav_GlobalDef_expr(node, info);
        break;
    }
    return node;
}

void replace_GlobalDef(struct GlobalDef *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_GlobalDef;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_GlobalDef: Not making a node replacement, since another replacement function was already called previously.");
    }
}

