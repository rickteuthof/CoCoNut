// Hash: 1b5e131a901dfeb50ab1b084b4472381
#pragma once
#include "generated/ast-For.h"

struct For *create_For(
       struct StmtList *block,
       struct Expr *boundexpr,
       struct Expr *initexpr,
       struct Expr *stepexpr,
       char * id);


