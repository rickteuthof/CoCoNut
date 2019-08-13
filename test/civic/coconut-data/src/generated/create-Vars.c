// Hash: e7edc9c998e6633c941feaada999a32e
#include "generated/create-Vars.h"

#include "generated/create-Var.h"
#include "generated/create-VarDec.h"
#include "generated/create-VarLet.h"
struct Vars *create_Vars_Var(struct Var *_Var) {
   struct Vars *res = mem_alloc(sizeof(struct Vars));
   res->type = NS_Vars_Var;
   res->value.val_Var = _Var;
   return res;
}

struct Vars *create_Vars_VarDec(struct VarDec *_VarDec) {
   struct Vars *res = mem_alloc(sizeof(struct Vars));
   res->type = NS_Vars_VarDec;
   res->value.val_VarDec = _VarDec;
   return res;
}

struct Vars *create_Vars_VarLet(struct VarLet *_VarLet) {
   struct Vars *res = mem_alloc(sizeof(struct Vars));
   res->type = NS_Vars_VarLet;
   res->value.val_VarLet = _VarLet;
   return res;
}


