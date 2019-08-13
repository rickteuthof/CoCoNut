// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#include "lib/memory.h"
#include "generated/ast-IfElse.h"
// ast-IfElse.h includes the neccesary attribute and children.
struct IfElse *create_IfElse(
       struct Expr *condition,
       struct StmtList *elseblock,
       struct StmtList *ifblock) {
   struct IfElse *res = mem_alloc(sizeof(struct IfElse));
   res->condition = condition;
   res->elseblock = elseblock;
   res->ifblock = ifblock;
   return res;
}


