// Hash: 2a17d582c98658539abe0f791e2036ae
#include "lib/memory.h"
#include "generated/ast-Symbol.h"
// ast-Symbol.h includes the neccesary attribute and children.
struct Symbol *create_Symbol(
       struct Symbol *next,
       bool export,
       bool external,
       char * name,
       int offset,
       int scope) {
   struct Symbol *res = mem_alloc(sizeof(struct Symbol));
   res->next = next;
   res->export = export;
   res->external = external;
   res->name = name;
   res->offset = offset;
   res->scope = scope;
   return res;
}


