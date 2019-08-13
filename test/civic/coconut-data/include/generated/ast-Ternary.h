// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#pragma once

typedef struct Expr Expr;
typedef struct Ternary {
    struct Expr *falseexpr;
    struct Expr *testexpr;
    struct Expr *trueexpr;
} Ternary;

