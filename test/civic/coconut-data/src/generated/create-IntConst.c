// Hash: e88afa1e610a0d88acf5ce24ec97f504
#include "lib/memory.h"
#include "generated/ast-IntConst.h"
// ast-IntConst.h includes the neccesary attribute and children.
struct IntConst *create_IntConst(
       int value) {
   struct IntConst *res = mem_alloc(sizeof(struct IntConst));
   res->value = value;
   return res;
}


