// Hash: df86d0e15495f375db62ae5bf23c0be7
#pragma once

typedef struct StmtList StmtList;
typedef struct Expr Expr;
typedef struct While {
    struct StmtList *block;
    struct Expr *condition;
} While;

