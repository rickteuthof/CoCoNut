// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-IfElse.h"
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
void _CCNtrav_StmtList(struct StmtList *node, struct Info *info);
void _CCNtrav_StmtList(struct StmtList *node, struct Info *info);

void CCNtrav_IfElse_condition(IfElse *node, struct Info *info) {
    node->condition = _CCNtrav_Expr(node->condition, info);
}

void CCNtrav_IfElse_elseblock(IfElse *node, struct Info *info) {
    node->elseblock = _CCNtrav_StmtList(node->elseblock, info);
}

void CCNtrav_IfElse_ifblock(IfElse *node, struct Info *info) {
    node->ifblock = _CCNtrav_StmtList(node->ifblock, info);
}

IfElse *_CCNtrav_IfElse(IfElse *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_IfElse(node, info);;
    default:
        CCNtrav_IfElse_condition(node, info);
        CCNtrav_IfElse_elseblock(node, info);
        CCNtrav_IfElse_ifblock(node, info);
        break;
    }
    return node;
}

void replace_IfElse(struct IfElse *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_IfElse;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_IfElse: Not making a node replacement, since another replacement function was already called previously.");
    }
}

