// Hash: b0bfe9d720169c1396aafc91b36ae925
#include "lib/memory.h"
#include "generated/ast-MonOp.h"
// ast-MonOp.h includes the neccesary attribute and children.
struct MonOp *create_MonOp(
       struct Expr *expr,
       MonOpEnum op) {
   struct MonOp *res = mem_alloc(sizeof(struct MonOp));
   res->expr = expr;
   res->op = op;
   return res;
}


