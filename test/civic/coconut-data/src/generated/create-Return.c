// Hash: 4b5f0f88bdd5355115a58de9c899d7b4
#include "lib/memory.h"
#include "generated/ast-Return.h"
// ast-Return.h includes the neccesary attribute and children.
struct Return *create_Return(
       struct Expr *expr) {
   struct Return *res = mem_alloc(sizeof(struct Return));
   res->expr = expr;
   return res;
}


