// Hash: 2a17d582c98658539abe0f791e2036ae
#pragma once
#include "generated/ast-Symbol.h"

struct Symbol *create_Symbol(
       struct Symbol *next,
       bool export,
       bool external,
       char * name,
       int offset,
       int scope);


