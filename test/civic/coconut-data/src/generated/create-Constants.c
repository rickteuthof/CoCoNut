// Hash: be4c521ad82189ec8e08be8055ccee09
#include "generated/create-Constants.h"

#include "generated/create-BoolConst.h"
#include "generated/create-FloatConst.h"
#include "generated/create-IntConst.h"
struct Constants *create_Constants_BoolConst(struct BoolConst *_BoolConst) {
   struct Constants *res = mem_alloc(sizeof(struct Constants));
   res->type = NS_Constants_BoolConst;
   res->value.val_BoolConst = _BoolConst;
   return res;
}

struct Constants *create_Constants_FloatConst(struct FloatConst *_FloatConst) {
   struct Constants *res = mem_alloc(sizeof(struct Constants));
   res->type = NS_Constants_FloatConst;
   res->value.val_FloatConst = _FloatConst;
   return res;
}

struct Constants *create_Constants_IntConst(struct IntConst *_IntConst) {
   struct Constants *res = mem_alloc(sizeof(struct Constants));
   res->type = NS_Constants_IntConst;
   res->value.val_IntConst = _IntConst;
   return res;
}


