// Hash: 33e19f933fee95125167d08907d344d2
#include "lib/memory.h"
#include "generated/ast-FunHeader.h"
// ast-FunHeader.h includes the neccesary attribute and children.
struct FunHeader *create_FunHeader(
       struct Param *params,
       char * id,
       BasicType rettype) {
   struct FunHeader *res = mem_alloc(sizeof(struct FunHeader));
   res->params = params;
   res->id = id;
   res->rettype = rettype;
   return res;
}


