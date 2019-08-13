// Hash: 70eba40e9dab0c2491717f2637a08068
#include "lib/memory.h"
#include "generated/ast-Root.h"
// ast-Root.h includes the neccesary attribute and children.
struct Root *create_Root(
       struct Decls *decls,
       struct FunSymbol *funsymbol,
       struct Symbol *symbol) {
   struct Root *res = mem_alloc(sizeof(struct Root));
   res->decls = decls;
   res->funsymbol = funsymbol;
   res->symbol = symbol;
   return res;
}


