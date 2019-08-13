// Hash: 1604aaf06d8e16acccd979c8275f8e32
#include "generated/create-Operations.h"

#include "generated/create-BinOp.h"
#include "generated/create-MonOp.h"
struct Operations *create_Operations_BinOp(struct BinOp *_BinOp) {
   struct Operations *res = mem_alloc(sizeof(struct Operations));
   res->type = NS_Operations_BinOp;
   res->value.val_BinOp = _BinOp;
   return res;
}

struct Operations *create_Operations_MonOp(struct MonOp *_MonOp) {
   struct Operations *res = mem_alloc(sizeof(struct Operations));
   res->type = NS_Operations_MonOp;
   res->value.val_MonOp = _MonOp;
   return res;
}


