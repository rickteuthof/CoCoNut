// Hash: d370e4383f7aab78470bbb20eac500e8
#include "lib/memory.h"
#include "generated/ast-GlobalDec.h"
// ast-GlobalDec.h includes the neccesary attribute and children.
struct GlobalDec *create_GlobalDec(
       char * id,
       BasicType type) {
   struct GlobalDec *res = mem_alloc(sizeof(struct GlobalDec));
   res->id = id;
   res->type = type;
   return res;
}


