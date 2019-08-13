// Hash: 0624d4152c0617b22ca17c7560e5b107
#pragma once

typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct ExprList {
    struct Expr *expr;
    struct ExprList *next;
} ExprList;

