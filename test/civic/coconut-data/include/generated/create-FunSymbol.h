// Hash: c25846fd3a15b982bb7497256c83a575
#pragma once
#include "generated/ast-FunSymbol.h"

struct FunSymbol *create_FunSymbol(
       struct FunSymbol *next,
       int arity,
       bool export,
       bool external,
       char * name,
       int offset,
       int scope,
       char * scopedname);


