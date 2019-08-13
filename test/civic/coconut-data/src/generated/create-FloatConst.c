// Hash: e53f745fb8225fc8c2f64b87c6517cb3
#include "lib/memory.h"
#include "generated/ast-FloatConst.h"
// ast-FloatConst.h includes the neccesary attribute and children.
struct FloatConst *create_FloatConst(
       float value) {
   struct FloatConst *res = mem_alloc(sizeof(struct FloatConst));
   res->value = value;
   return res;
}


