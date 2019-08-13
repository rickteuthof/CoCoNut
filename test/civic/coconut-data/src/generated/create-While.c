// Hash: df86d0e15495f375db62ae5bf23c0be7
#include "lib/memory.h"
#include "generated/ast-While.h"
// ast-While.h includes the neccesary attribute and children.
struct While *create_While(
       struct StmtList *block,
       struct Expr *condition) {
   struct While *res = mem_alloc(sizeof(struct While));
   res->block = block;
   res->condition = condition;
   return res;
}


