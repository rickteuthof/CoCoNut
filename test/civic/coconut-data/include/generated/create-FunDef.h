// Hash: 1e4fc8c57864026894e956f2ce63ce36
#pragma once
#include "generated/ast-FunDef.h"

struct FunDef *create_FunDef(
       struct FunBody *funbody,
       struct FunHeader *funheader,
       struct FunSymbol *funsymbol,
       struct FunDef *next,
       struct Symbol *symbol,
       bool export,
       bool external);


