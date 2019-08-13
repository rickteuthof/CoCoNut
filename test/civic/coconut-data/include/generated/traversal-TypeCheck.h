// Hash: afa7b464d323a16d64e418bcca36b700
#pragma once

#include "generated/ast.h"
#include "generated/trav-BinOp.h"
#include "generated/trav-BoolConst.h"
#include "generated/trav-Cast.h"
#include "generated/trav-DoWhile.h"
#include "generated/trav-FloatConst.h"
#include "generated/trav-For.h"
#include "generated/trav-FunBody.h"
#include "generated/trav-FunCall.h"
#include "generated/trav-FunDef.h"
#include "generated/trav-FunHeader.h"
#include "generated/trav-IfElse.h"
#include "generated/trav-IntConst.h"
#include "generated/trav-MonOp.h"
#include "generated/trav-Param.h"
#include "generated/trav-Return.h"
#include "generated/trav-Var.h"
#include "generated/trav-VarLet.h"
#include "generated/trav-While.h"
typedef struct Info Info;
Info *TypeCheck_createinfo(void);
void TypeCheck_freeinfo(Info *);
void TypeCheck_BinOp(BinOp *node, Info *info);
void TypeCheck_BoolConst(BoolConst *node, Info *info);
void TypeCheck_Cast(Cast *node, Info *info);
void TypeCheck_DoWhile(DoWhile *node, Info *info);
void TypeCheck_FloatConst(FloatConst *node, Info *info);
void TypeCheck_For(For *node, Info *info);
void TypeCheck_FunBody(FunBody *node, Info *info);
void TypeCheck_FunCall(FunCall *node, Info *info);
void TypeCheck_FunDef(FunDef *node, Info *info);
void TypeCheck_FunHeader(FunHeader *node, Info *info);
void TypeCheck_IfElse(IfElse *node, Info *info);
void TypeCheck_IntConst(IntConst *node, Info *info);
void TypeCheck_MonOp(MonOp *node, Info *info);
void TypeCheck_Param(Param *node, Info *info);
void TypeCheck_Return(Return *node, Info *info);
void TypeCheck_Var(Var *node, Info *info);
void TypeCheck_VarLet(VarLet *node, Info *info);
void TypeCheck_While(While *node, Info *info);

