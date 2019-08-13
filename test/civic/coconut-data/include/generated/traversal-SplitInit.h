// Hash: 0267045945ee83ca7303ca6c8c141d7e
#pragma once

#include "generated/ast.h"
#include "generated/trav-FunBody.h"
#include "generated/trav-GlobalDef.h"
#include "generated/trav-Root.h"
#include "generated/trav-VarDec.h"
typedef struct Info Info;
Info *SplitInit_createinfo(void);
void SplitInit_freeinfo(Info *);
void SplitInit_FunBody(FunBody *node, Info *info);
void SplitInit_GlobalDef(GlobalDef *node, Info *info);
void SplitInit_Root(Root *node, Info *info);
void SplitInit_VarDec(VarDec *node, Info *info);

