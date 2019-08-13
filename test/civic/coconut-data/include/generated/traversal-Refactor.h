// Hash: e2d86a494f03e27a1e8ba19ec2af70a1
#pragma once

#include "generated/ast.h"
#include "generated/trav-BinOp.h"
#include "generated/trav-BoolConst.h"
#include "generated/trav-Cast.h"
#include "generated/trav-FloatConst.h"
#include "generated/trav-FunCall.h"
#include "generated/trav-IntConst.h"
#include "generated/trav-StmtList.h"
#include "generated/trav-Var.h"
#include "generated/trav-While.h"
typedef struct Info Info;
Info *Refactor_createinfo(void);
void Refactor_freeinfo(Info *);
void Refactor_BinOp(BinOp *node, Info *info);
void Refactor_BoolConst(BoolConst *node, Info *info);
void Refactor_Cast(Cast *node, Info *info);
void Refactor_FloatConst(FloatConst *node, Info *info);
void Refactor_FunCall(FunCall *node, Info *info);
void Refactor_IntConst(IntConst *node, Info *info);
void Refactor_StmtList(StmtList *node, Info *info);
void Refactor_Var(Var *node, Info *info);
void Refactor_While(While *node, Info *info);

