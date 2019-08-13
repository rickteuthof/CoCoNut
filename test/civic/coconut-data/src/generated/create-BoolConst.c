// Hash: 657816c98ab8bae4509f890a4cf4b654
#include "lib/memory.h"
#include "generated/ast-BoolConst.h"
// ast-BoolConst.h includes the neccesary attribute and children.
struct BoolConst *create_BoolConst(
       bool value) {
   struct BoolConst *res = mem_alloc(sizeof(struct BoolConst));
   res->value = value;
   return res;
}


