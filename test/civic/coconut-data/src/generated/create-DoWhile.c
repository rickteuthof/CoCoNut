// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
#include "lib/memory.h"
#include "generated/ast-DoWhile.h"
// ast-DoWhile.h includes the neccesary attribute and children.
struct DoWhile *create_DoWhile(
       struct StmtList *block,
       struct Expr *condition) {
   struct DoWhile *res = mem_alloc(sizeof(struct DoWhile));
   res->block = block;
   res->condition = condition;
   return res;
}


