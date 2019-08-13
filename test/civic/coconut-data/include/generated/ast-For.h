// Hash: 1b5e131a901dfeb50ab1b084b4472381
#pragma once

typedef struct StmtList StmtList;
typedef struct Expr Expr;
struct Symbol;
typedef struct For {
    struct StmtList *block;
    struct Expr *boundexpr;
    struct Expr *initexpr;
    struct Expr *stepexpr;
    char * id;
    struct Symbol * symbol;
} For;

