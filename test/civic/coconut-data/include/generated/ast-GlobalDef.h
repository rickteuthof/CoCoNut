// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#pragma once

typedef struct Expr Expr;
struct Symbol;
#include "generated/enum.h"
#include <stdbool.h>
typedef struct GlobalDef {
    struct Expr *expr;
    bool export;
    char * id;
    struct Symbol * symbol;
    BasicType type;
} GlobalDef;

