// Hash: 335492ed82f8520c39ccbce6a5739af7
#include "lib/memory.h"
#include "generated/ast-LocalFunDef.h"
// ast-LocalFunDef.h includes the neccesary attribute and children.
struct LocalFunDef *create_LocalFunDef(
       struct FunDef *decl,
       struct LocalFunDef *next) {
   struct LocalFunDef *res = mem_alloc(sizeof(struct LocalFunDef));
   res->decl = decl;
   res->next = next;
   return res;
}


