// Hash: 1e4fc8c57864026894e956f2ce63ce36
#include "lib/memory.h"
#include "generated/ast-FunDef.h"
// ast-FunDef.h includes the neccesary attribute and children.
struct FunDef *create_FunDef(
       struct FunBody *funbody,
       struct FunHeader *funheader,
       struct FunSymbol *funsymbol,
       struct FunDef *next,
       struct Symbol *symbol,
       bool export,
       bool external) {
   struct FunDef *res = mem_alloc(sizeof(struct FunDef));
   res->funbody = funbody;
   res->funheader = funheader;
   res->funsymbol = funsymbol;
   res->next = next;
   res->symbol = symbol;
   res->export = export;
   res->external = external;
   return res;
}


