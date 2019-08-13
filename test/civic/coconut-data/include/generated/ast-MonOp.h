// Hash: b0bfe9d720169c1396aafc91b36ae925
#pragma once

typedef struct Expr Expr;
#include "generated/enum.h"
typedef struct MonOp {
    struct Expr *expr;
    MonOpEnum op;
} MonOp;

