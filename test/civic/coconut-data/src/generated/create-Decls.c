// Hash: da1486863569ad210a4555708de59ea2
#include "lib/memory.h"
#include "generated/ast-Decls.h"
// ast-Decls.h includes the neccesary attribute and children.
struct Decls *create_Decls(
       struct Decl *decl,
       struct Decls *next) {
   struct Decls *res = mem_alloc(sizeof(struct Decls));
   res->decl = decl;
   res->next = next;
   return res;
}


