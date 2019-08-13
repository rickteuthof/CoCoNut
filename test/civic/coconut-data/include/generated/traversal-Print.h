// Hash: 13dba24862cf9128167a59100e154c8d
#pragma once

#include "generated/ast.h"
#include "generated/trav-ast.h"
typedef struct Info Info;
Info *Print_createinfo(void);
void Print_freeinfo(Info *);
void Print_BinOp(BinOp *node, Info *info);
void Print_BoolConst(BoolConst *node, Info *info);
void Print_Cast(Cast *node, Info *info);
void Print_Decls(Decls *node, Info *info);
void Print_DoWhile(DoWhile *node, Info *info);
void Print_ExprList(ExprList *node, Info *info);
void Print_FloatConst(FloatConst *node, Info *info);
void Print_For(For *node, Info *info);
void Print_FunBody(FunBody *node, Info *info);
void Print_FunCall(FunCall *node, Info *info);
void Print_FunDef(FunDef *node, Info *info);
void Print_FunHeader(FunHeader *node, Info *info);
void Print_FunSymbol(FunSymbol *node, Info *info);
void Print_GlobalDec(GlobalDec *node, Info *info);
void Print_GlobalDef(GlobalDef *node, Info *info);
void Print_IfElse(IfElse *node, Info *info);
void Print_IntConst(IntConst *node, Info *info);
void Print_LocalFunDef(LocalFunDef *node, Info *info);
void Print_MonOp(MonOp *node, Info *info);
void Print_Param(Param *node, Info *info);
void Print_Return(Return *node, Info *info);
void Print_Root(Root *node, Info *info);
void Print_StmtList(StmtList *node, Info *info);
void Print_Symbol(Symbol *node, Info *info);
void Print_Ternary(Ternary *node, Info *info);
void Print_Var(Var *node, Info *info);
void Print_VarDec(VarDec *node, Info *info);
void Print_VarLet(VarLet *node, Info *info);
void Print_While(While *node, Info *info);

