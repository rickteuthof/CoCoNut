// Hash: af28c29a686569d7ebb3c15611b384d2
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-StmtList.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_StmtList(struct StmtList *node, struct Info *info);
void _CCNtrav_DoWhile(struct DoWhile *node, struct Info *info);
void _CCNtrav_For(struct For *node, struct Info *info);
void _CCNtrav_FunCall(struct FunCall *node, struct Info *info);
void _CCNtrav_IfElse(struct IfElse *node, struct Info *info);
void _CCNtrav_Return(struct Return *node, struct Info *info);
void _CCNtrav_VarLet(struct VarLet *node, struct Info *info);
void _CCNtrav_While(struct While *node, struct Info *info);

void CCNtrav_StmtList_next(StmtList *node, struct Info *info) {
    node->next = _CCNtrav_StmtList(node->next, info);
}

void CCNtrav_StmtList_stmt(StmtList *node, struct Info *info) {
    node->stmt = _CCNtrav_Stmt(node->stmt, info);
}

StmtList *_CCNtrav_StmtList(StmtList *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_StmtList(node, info);;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    default:
        CCNtrav_StmtList_next(node, info);
        CCNtrav_StmtList_stmt(node, info);
        break;
    }
    return node;
}

void replace_StmtList(struct StmtList *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_StmtList;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_StmtList: Not making a node replacement, since another replacement function was already called previously.");
    }
}

