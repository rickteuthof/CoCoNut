// Hash: cc2abd438fff2facf1c543ad95507122
#include "lib/memory.h"
#include "generated/ast-FunCall.h"
// ast-FunCall.h includes the neccesary attribute and children.
struct FunCall *create_FunCall(
       struct ExprList *params,
       char * id) {
   struct FunCall *res = mem_alloc(sizeof(struct FunCall));
   res->params = params;
   res->id = id;
   res->symbol = NULL;
   return res;
}


