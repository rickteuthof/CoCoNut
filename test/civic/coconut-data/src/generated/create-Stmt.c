// Hash: bb6639b82c8f18c2af9886944317b845
#include "generated/create-Stmt.h"

#include "generated/create-DoWhile.h"
#include "generated/create-For.h"
#include "generated/create-FunCall.h"
#include "generated/create-IfElse.h"
#include "generated/create-Return.h"
#include "generated/create-VarLet.h"
#include "generated/create-While.h"
struct Stmt *create_Stmt_DoWhile(struct DoWhile *_DoWhile) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_DoWhile;
   res->value.val_DoWhile = _DoWhile;
   return res;
}

struct Stmt *create_Stmt_For(struct For *_For) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_For;
   res->value.val_For = _For;
   return res;
}

struct Stmt *create_Stmt_FunCall(struct FunCall *_FunCall) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_FunCall;
   res->value.val_FunCall = _FunCall;
   return res;
}

struct Stmt *create_Stmt_IfElse(struct IfElse *_IfElse) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_IfElse;
   res->value.val_IfElse = _IfElse;
   return res;
}

struct Stmt *create_Stmt_Return(struct Return *_Return) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_Return;
   res->value.val_Return = _Return;
   return res;
}

struct Stmt *create_Stmt_VarLet(struct VarLet *_VarLet) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_VarLet;
   res->value.val_VarLet = _VarLet;
   return res;
}

struct Stmt *create_Stmt_While(struct While *_While) {
   struct Stmt *res = mem_alloc(sizeof(struct Stmt));
   res->type = NS_Stmt_While;
   res->value.val_While = _While;
   return res;
}


