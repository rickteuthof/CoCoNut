// Hash: df86d0e15495f375db62ae5bf23c0be7
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-While.h"
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

void CCNtrav_While_block(While *node, struct Info *info) {
    node->block = _CCNtrav_StmtList(node->block, info);
}

void CCNtrav_While_condition(While *node, struct Info *info) {
    node->condition = _CCNtrav_Expr(node->condition, info);
}

While *_CCNtrav_While(While *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_While(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_While(node, info);;
    default:
        CCNtrav_While_block(node, info);
        CCNtrav_While_condition(node, info);
        break;
    }
    return node;
}

void replace_While(struct While *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_While;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_While: Not making a node replacement, since another replacement function was already called previously.");
    }
}

