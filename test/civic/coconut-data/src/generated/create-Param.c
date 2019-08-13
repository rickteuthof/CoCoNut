// Hash: 31ba4afd09094183d749087a75279dea
#include "lib/memory.h"
#include "generated/ast-Param.h"
// ast-Param.h includes the neccesary attribute and children.
struct Param *create_Param(
       struct Param *next,
       char * id,
       BasicType type) {
   struct Param *res = mem_alloc(sizeof(struct Param));
   res->next = next;
   res->id = id;
   res->type = type;
   return res;
}


