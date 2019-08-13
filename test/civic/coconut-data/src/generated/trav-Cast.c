// Hash: b42c3d81e8cab965bf25d8b307a365f2
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Cast.h"
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

void CCNtrav_Cast_expr(Cast *node, struct Info *info) {
    node->expr = _CCNtrav_Expr(node->expr, info);
}

Cast *_CCNtrav_Cast(Cast *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_Cast(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_Cast(node, info);;
    default:
        CCNtrav_Cast_expr(node, info);
        break;
    }
    return node;
}

void replace_Cast(struct Cast *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Cast;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Cast: Not making a node replacement, since another replacement function was already called previously.");
    }
}

