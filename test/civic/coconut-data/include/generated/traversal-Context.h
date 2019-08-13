// Hash: 78963497cb962d787aa83c05bdf77034
#pragma once

#include "generated/ast.h"
#include "generated/trav-For.h"
#include "generated/trav-FunCall.h"
#include "generated/trav-FunDef.h"
#include "generated/trav-GlobalDec.h"
#include "generated/trav-GlobalDef.h"
#include "generated/trav-Param.h"
#include "generated/trav-Root.h"
#include "generated/trav-Var.h"
#include "generated/trav-VarDec.h"
#include "generated/trav-VarLet.h"
typedef struct Info Info;
Info *Context_createinfo(void);
void Context_freeinfo(Info *);
void Context_For(For *node, Info *info);
void Context_FunCall(FunCall *node, Info *info);
void Context_FunDef(FunDef *node, Info *info);
void Context_GlobalDec(GlobalDec *node, Info *info);
void Context_GlobalDef(GlobalDef *node, Info *info);
void Context_Param(Param *node, Info *info);
void Context_Root(Root *node, Info *info);
void Context_Var(Var *node, Info *info);
void Context_VarDec(VarDec *node, Info *info);
void Context_VarLet(VarLet *node, Info *info);

