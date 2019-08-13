// Hash: b42c3d81e8cab965bf25d8b307a365f2
#include "lib/memory.h"
#include "generated/ast-Cast.h"
// ast-Cast.h includes the neccesary attribute and children.
struct Cast *create_Cast(
       struct Expr *expr,
       BasicType type) {
   struct Cast *res = mem_alloc(sizeof(struct Cast));
   res->expr = expr;
   res->type = type;
   return res;
}


