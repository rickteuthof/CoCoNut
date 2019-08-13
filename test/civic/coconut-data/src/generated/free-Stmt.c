// Hash: bb6639b82c8f18c2af9886944317b845
#include "generated/free-Stmt.h"

#include "generated/free-DoWhile.h"
#include "generated/free-For.h"
#include "generated/free-FunCall.h"
#include "generated/free-IfElse.h"
#include "generated/free-Return.h"
#include "generated/free-VarLet.h"
#include "generated/free-While.h"
void free_Stmt_tree(struct Stmt *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Stmt_DoWhile:
        free_DoWhile_tree(nodeset->value.val_DoWhile);
        break;
    case NS_Stmt_For:
        free_For_tree(nodeset->value.val_For);
        break;
    case NS_Stmt_FunCall:
        free_FunCall_tree(nodeset->value.val_FunCall);
        break;
    case NS_Stmt_IfElse:
        free_IfElse_tree(nodeset->value.val_IfElse);
        break;
    case NS_Stmt_Return:
        free_Return_tree(nodeset->value.val_Return);
        break;
    case NS_Stmt_VarLet:
        free_VarLet_tree(nodeset->value.val_VarLet);
        break;
    case NS_Stmt_While:
        free_While_tree(nodeset->value.val_While);
        break;
    }
    mem_free(nodeset);
}
void free_Stmt_node(struct Stmt* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Stmt_DoWhile:
        free_DoWhile_node(nodeset->value.val_DoWhile);
        break;
    case NS_Stmt_For:
        free_For_node(nodeset->value.val_For);
        break;
    case NS_Stmt_FunCall:
        free_FunCall_node(nodeset->value.val_FunCall);
        break;
    case NS_Stmt_IfElse:
        free_IfElse_node(nodeset->value.val_IfElse);
        break;
    case NS_Stmt_Return:
        free_Return_node(nodeset->value.val_Return);
        break;
    case NS_Stmt_VarLet:
        free_VarLet_node(nodeset->value.val_VarLet);
        break;
    case NS_Stmt_While:
        free_While_node(nodeset->value.val_While);
        break;
    }
    mem_free(nodeset);
}

