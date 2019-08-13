// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#pragma once
#include "generated/ast-GlobalDef.h"

struct GlobalDef *create_GlobalDef(
       struct Expr *expr,
       bool export,
       char * id,
       BasicType type);


