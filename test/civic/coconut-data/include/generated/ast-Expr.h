// Hash: 6d316f510e6ccaf4826835131137a57e
#pragma once

// Forward declarations of children.
typedef struct BinOp BinOp;
typedef struct BoolConst BoolConst;
typedef struct Cast Cast;
typedef struct FloatConst FloatConst;
typedef struct FunCall FunCall;
typedef struct IntConst IntConst;
typedef struct MonOp MonOp;
typedef struct Ternary Ternary;
typedef struct Var Var;
// Nodeset Expr
typedef enum { NS_Expr_BinOp, NS_Expr_BoolConst, NS_Expr_Cast, NS_Expr_FloatConst, NS_Expr_FunCall, NS_Expr_IntConst, NS_Expr_MonOp, NS_Expr_Ternary, NS_Expr_Var, } NS_Expr_enum;
typedef struct Expr {
    union {
        struct BinOp *val_BinOp;
        struct BoolConst *val_BoolConst;
        struct Cast *val_Cast;
        struct FloatConst *val_FloatConst;
        struct FunCall *val_FunCall;
        struct IntConst *val_IntConst;
        struct MonOp *val_MonOp;
        struct Ternary *val_Ternary;
        struct Var *val_Var;
    } value;
    NS_Expr_enum type;
} Expr;


