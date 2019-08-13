// Hash: 6d316f510e6ccaf4826835131137a57e
#include "generated/create-Expr.h"

#include "generated/create-BinOp.h"
#include "generated/create-BoolConst.h"
#include "generated/create-Cast.h"
#include "generated/create-FloatConst.h"
#include "generated/create-FunCall.h"
#include "generated/create-IntConst.h"
#include "generated/create-MonOp.h"
#include "generated/create-Ternary.h"
#include "generated/create-Var.h"
struct Expr *create_Expr_BinOp(struct BinOp *_BinOp) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_BinOp;
   res->value.val_BinOp = _BinOp;
   return res;
}

struct Expr *create_Expr_BoolConst(struct BoolConst *_BoolConst) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_BoolConst;
   res->value.val_BoolConst = _BoolConst;
   return res;
}

struct Expr *create_Expr_Cast(struct Cast *_Cast) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_Cast;
   res->value.val_Cast = _Cast;
   return res;
}

struct Expr *create_Expr_FloatConst(struct FloatConst *_FloatConst) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_FloatConst;
   res->value.val_FloatConst = _FloatConst;
   return res;
}

struct Expr *create_Expr_FunCall(struct FunCall *_FunCall) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_FunCall;
   res->value.val_FunCall = _FunCall;
   return res;
}

struct Expr *create_Expr_IntConst(struct IntConst *_IntConst) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_IntConst;
   res->value.val_IntConst = _IntConst;
   return res;
}

struct Expr *create_Expr_MonOp(struct MonOp *_MonOp) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_MonOp;
   res->value.val_MonOp = _MonOp;
   return res;
}

struct Expr *create_Expr_Ternary(struct Ternary *_Ternary) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_Ternary;
   res->value.val_Ternary = _Ternary;
   return res;
}

struct Expr *create_Expr_Var(struct Var *_Var) {
   struct Expr *res = mem_alloc(sizeof(struct Expr));
   res->type = NS_Expr_Var;
   res->value.val_Var = _Var;
   return res;
}


