// Hash: 0624d4152c0617b22ca17c7560e5b107
#include "lib/memory.h"
#include "generated/ast-ExprList.h"
// ast-ExprList.h includes the neccesary attribute and children.
struct ExprList *create_ExprList(
       struct Expr *expr,
       struct ExprList *next) {
   struct ExprList *res = mem_alloc(sizeof(struct ExprList));
   res->expr = expr;
   res->next = next;
   return res;
}


