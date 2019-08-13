// Hash: 6d316f510e6ccaf4826835131137a57e
#pragma once
#include "lib/memory.h"
#include "generated/ast.h"

struct Expr *create_Expr_BinOp(struct BinOp *_BinOp);

struct Expr *create_Expr_BoolConst(struct BoolConst *_BoolConst);

struct Expr *create_Expr_Cast(struct Cast *_Cast);

struct Expr *create_Expr_FloatConst(struct FloatConst *_FloatConst);

struct Expr *create_Expr_FunCall(struct FunCall *_FunCall);

struct Expr *create_Expr_IntConst(struct IntConst *_IntConst);

struct Expr *create_Expr_MonOp(struct MonOp *_MonOp);

struct Expr *create_Expr_Ternary(struct Ternary *_Ternary);

struct Expr *create_Expr_Var(struct Var *_Var);


