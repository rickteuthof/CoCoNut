// Hash: 514d9d5eed2b7d56245866708d0e1d89
#pragma once

typedef struct Expr Expr;
#include "generated/enum.h"
typedef struct BinOp {
    struct Expr *left;
    struct Expr *right;
    BinOpEnum op;
} BinOp;

