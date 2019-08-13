// Hash: 1fabc23d00d09394712ebc11a0e33a24
#pragma once

typedef struct Expr Expr;
struct Symbol;
typedef struct VarLet {
    struct Expr *expr;
    char * id;
    struct Symbol * symbol;
} VarLet;

