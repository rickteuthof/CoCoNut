// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#pragma once
#include "generated/ast-Ternary.h"

struct Ternary *create_Ternary(
       struct Expr *falseexpr,
       struct Expr *testexpr,
       struct Expr *trueexpr);


