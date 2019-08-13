// Hash: c25846fd3a15b982bb7497256c83a575
#include "lib/memory.h"
#include "generated/ast-FunSymbol.h"
// ast-FunSymbol.h includes the neccesary attribute and children.
struct FunSymbol *create_FunSymbol(
       struct FunSymbol *next,
       int arity,
       bool export,
       bool external,
       char * name,
       int offset,
       int scope,
       char * scopedname) {
   struct FunSymbol *res = mem_alloc(sizeof(struct FunSymbol));
   res->next = next;
   res->arity = arity;
   res->export = export;
   res->external = external;
   res->name = name;
   res->offset = offset;
   res->scope = scope;
   res->scopedname = scopedname;
   return res;
}


