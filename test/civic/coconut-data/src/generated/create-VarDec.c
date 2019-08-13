// Hash: 3e39a0cd59728ac5797ddd72e5100164
#include "lib/memory.h"
#include "generated/ast-VarDec.h"
// ast-VarDec.h includes the neccesary attribute and children.
struct VarDec *create_VarDec(
       struct Expr *expr,
       struct VarDec *next,
       char * id,
       BasicType type) {
   struct VarDec *res = mem_alloc(sizeof(struct VarDec));
   res->expr = expr;
   res->next = next;
   res->id = id;
   res->symbol = NULL;
   res->type = type;
   return res;
}


