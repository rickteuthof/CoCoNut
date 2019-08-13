// Hash: b42c3d81e8cab965bf25d8b307a365f2
#pragma once

typedef struct Expr Expr;
#include "generated/enum.h"
typedef struct Cast {
    struct Expr *expr;
    BasicType type;
} Cast;

