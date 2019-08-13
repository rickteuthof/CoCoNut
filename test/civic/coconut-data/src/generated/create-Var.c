// Hash: 121eeb949095a740dd78338f981bac61
#include "lib/memory.h"
#include "generated/ast-Var.h"
// ast-Var.h includes the neccesary attribute and children.
struct Var *create_Var(
       char * id) {
   struct Var *res = mem_alloc(sizeof(struct Var));
   res->id = id;
   res->symbol = NULL;
   return res;
}


