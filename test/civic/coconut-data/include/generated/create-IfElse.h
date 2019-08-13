// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#pragma once
#include "generated/ast-IfElse.h"

struct IfElse *create_IfElse(
       struct Expr *condition,
       struct StmtList *elseblock,
       struct StmtList *ifblock);


