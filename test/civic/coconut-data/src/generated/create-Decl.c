// Hash: a1b06fb9abb037787acc985178482577
#include "generated/create-Decl.h"

#include "generated/create-FunDef.h"
#include "generated/create-GlobalDec.h"
#include "generated/create-GlobalDef.h"
struct Decl *create_Decl_FunDef(struct FunDef *_FunDef) {
   struct Decl *res = mem_alloc(sizeof(struct Decl));
   res->type = NS_Decl_FunDef;
   res->value.val_FunDef = _FunDef;
   return res;
}

struct Decl *create_Decl_GlobalDec(struct GlobalDec *_GlobalDec) {
   struct Decl *res = mem_alloc(sizeof(struct Decl));
   res->type = NS_Decl_GlobalDec;
   res->value.val_GlobalDec = _GlobalDec;
   return res;
}

struct Decl *create_Decl_GlobalDef(struct GlobalDef *_GlobalDef) {
   struct Decl *res = mem_alloc(sizeof(struct Decl));
   res->type = NS_Decl_GlobalDef;
   res->value.val_GlobalDef = _GlobalDef;
   return res;
}


