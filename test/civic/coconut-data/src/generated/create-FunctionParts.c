// Hash: 782f9b0b6daa7e2b74e6825788ce728f
#include "generated/create-FunctionParts.h"

#include "generated/create-FunBody.h"
#include "generated/create-FunDef.h"
#include "generated/create-FunHeader.h"
#include "generated/create-Param.h"
struct FunctionParts *create_FunctionParts_FunBody(struct FunBody *_FunBody) {
   struct FunctionParts *res = mem_alloc(sizeof(struct FunctionParts));
   res->type = NS_FunctionParts_FunBody;
   res->value.val_FunBody = _FunBody;
   return res;
}

struct FunctionParts *create_FunctionParts_FunDef(struct FunDef *_FunDef) {
   struct FunctionParts *res = mem_alloc(sizeof(struct FunctionParts));
   res->type = NS_FunctionParts_FunDef;
   res->value.val_FunDef = _FunDef;
   return res;
}

struct FunctionParts *create_FunctionParts_FunHeader(struct FunHeader *_FunHeader) {
   struct FunctionParts *res = mem_alloc(sizeof(struct FunctionParts));
   res->type = NS_FunctionParts_FunHeader;
   res->value.val_FunHeader = _FunHeader;
   return res;
}

struct FunctionParts *create_FunctionParts_Param(struct Param *_Param) {
   struct FunctionParts *res = mem_alloc(sizeof(struct FunctionParts));
   res->type = NS_FunctionParts_Param;
   res->value.val_Param = _Param;
   return res;
}


