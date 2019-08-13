// Hash: 6d316f510e6ccaf4826835131137a57e
#include "generated/free-Expr.h"

#include "generated/free-BinOp.h"
#include "generated/free-BoolConst.h"
#include "generated/free-Cast.h"
#include "generated/free-FloatConst.h"
#include "generated/free-FunCall.h"
#include "generated/free-IntConst.h"
#include "generated/free-MonOp.h"
#include "generated/free-Ternary.h"
#include "generated/free-Var.h"
void free_Expr_tree(struct Expr *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Expr_BinOp:
        free_BinOp_tree(nodeset->value.val_BinOp);
        break;
    case NS_Expr_BoolConst:
        free_BoolConst_tree(nodeset->value.val_BoolConst);
        break;
    case NS_Expr_Cast:
        free_Cast_tree(nodeset->value.val_Cast);
        break;
    case NS_Expr_FloatConst:
        free_FloatConst_tree(nodeset->value.val_FloatConst);
        break;
    case NS_Expr_FunCall:
        free_FunCall_tree(nodeset->value.val_FunCall);
        break;
    case NS_Expr_IntConst:
        free_IntConst_tree(nodeset->value.val_IntConst);
        break;
    case NS_Expr_MonOp:
        free_MonOp_tree(nodeset->value.val_MonOp);
        break;
    case NS_Expr_Ternary:
        free_Ternary_tree(nodeset->value.val_Ternary);
        break;
    case NS_Expr_Var:
        free_Var_tree(nodeset->value.val_Var);
        break;
    }
    mem_free(nodeset);
}
void free_Expr_node(struct Expr* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Expr_BinOp:
        free_BinOp_node(nodeset->value.val_BinOp);
        break;
    case NS_Expr_BoolConst:
        free_BoolConst_node(nodeset->value.val_BoolConst);
        break;
    case NS_Expr_Cast:
        free_Cast_node(nodeset->value.val_Cast);
        break;
    case NS_Expr_FloatConst:
        free_FloatConst_node(nodeset->value.val_FloatConst);
        break;
    case NS_Expr_FunCall:
        free_FunCall_node(nodeset->value.val_FunCall);
        break;
    case NS_Expr_IntConst:
        free_IntConst_node(nodeset->value.val_IntConst);
        break;
    case NS_Expr_MonOp:
        free_MonOp_node(nodeset->value.val_MonOp);
        break;
    case NS_Expr_Ternary:
        free_Ternary_node(nodeset->value.val_Ternary);
        break;
    case NS_Expr_Var:
        free_Var_node(nodeset->value.val_Var);
        break;
    }
    mem_free(nodeset);
}

