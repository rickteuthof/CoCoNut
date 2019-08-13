// Hash: 1b5e131a901dfeb50ab1b084b4472381
#include "lib/memory.h"
#include "generated/ast-For.h"
// ast-For.h includes the neccesary attribute and children.
struct For *create_For(
       struct StmtList *block,
       struct Expr *boundexpr,
       struct Expr *initexpr,
       struct Expr *stepexpr,
       char * id) {
   struct For *res = mem_alloc(sizeof(struct For));
   res->block = block;
   res->boundexpr = boundexpr;
   res->initexpr = initexpr;
   res->stepexpr = stepexpr;
   res->id = id;
   res->symbol = NULL;
   return res;
}


