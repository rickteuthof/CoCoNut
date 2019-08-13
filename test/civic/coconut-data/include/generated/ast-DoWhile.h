// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
#pragma once

typedef struct StmtList StmtList;
typedef struct Expr Expr;
typedef struct DoWhile {
    struct StmtList *block;
    struct Expr *condition;
} DoWhile;

