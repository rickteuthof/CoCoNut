// Hash: 514d9d5eed2b7d56245866708d0e1d89
#pragma once
#include "generated/ast-BinOp.h"

struct BinOp *create_BinOp(
       struct Expr *left,
       struct Expr *right,
       BinOpEnum op);


