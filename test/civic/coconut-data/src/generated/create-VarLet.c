// Hash: 1fabc23d00d09394712ebc11a0e33a24
#include "lib/memory.h"
#include "generated/ast-VarLet.h"
// ast-VarLet.h includes the neccesary attribute and children.
struct VarLet *create_VarLet(
       struct Expr *expr,
       char * id) {
   struct VarLet *res = mem_alloc(sizeof(struct VarLet));
   res->expr = expr;
   res->id = id;
   res->symbol = NULL;
   return res;
}


