// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#include "lib/memory.h"
#include "generated/ast-GlobalDef.h"
// ast-GlobalDef.h includes the neccesary attribute and children.
struct GlobalDef *create_GlobalDef(
       struct Expr *expr,
       bool export,
       char * id,
       BasicType type) {
   struct GlobalDef *res = mem_alloc(sizeof(struct GlobalDef));
   res->expr = expr;
   res->export = export;
   res->id = id;
   res->symbol = NULL;
   res->type = type;
   return res;
}


