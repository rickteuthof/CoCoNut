// Hash: 3e39a0cd59728ac5797ddd72e5100164
#pragma once

typedef struct Expr Expr;
typedef struct VarDec VarDec;
struct Symbol;
#include "generated/enum.h"
typedef struct VarDec {
    struct Expr *expr;
    struct VarDec *next;
    char * id;
    struct Symbol * symbol;
    BasicType type;
} VarDec;

