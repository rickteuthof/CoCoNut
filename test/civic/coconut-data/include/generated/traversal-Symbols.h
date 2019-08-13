// Hash: 444509a21a47d3a89328fb5ac2270a08
#pragma once

#include "generated/ast.h"
#include "generated/trav-FunDef.h"
#include "generated/trav-FunSymbol.h"
#include "generated/trav-Root.h"
#include "generated/trav-Symbol.h"
typedef struct Info Info;
Info *Symbols_createinfo(void);
void Symbols_freeinfo(Info *);
void Symbols_FunDef(FunDef *node, Info *info);
void Symbols_FunSymbol(FunSymbol *node, Info *info);
void Symbols_Root(Root *node, Info *info);
void Symbols_Symbol(Symbol *node, Info *info);

