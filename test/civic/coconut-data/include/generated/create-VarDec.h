// Hash: 3e39a0cd59728ac5797ddd72e5100164
#pragma once
#include "generated/ast-VarDec.h"

struct VarDec *create_VarDec(
       struct Expr *expr,
       struct VarDec *next,
       char * id,
       BasicType type);


