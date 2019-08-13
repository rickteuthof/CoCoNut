// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#pragma once

typedef struct Expr Expr;
typedef struct StmtList StmtList;
typedef struct IfElse {
    struct Expr *condition;
    struct StmtList *elseblock;
    struct StmtList *ifblock;
} IfElse;

