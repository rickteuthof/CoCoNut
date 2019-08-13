// Hash: b749bf704b901788bcd7cb60caea2822
#include "lib/memory.h"
#include "generated/ast-FunBody.h"
// ast-FunBody.h includes the neccesary attribute and children.
struct FunBody *create_FunBody(
       struct LocalFunDef *localfundef,
       struct StmtList *stmtlist,
       struct VarDec *vardec) {
   struct FunBody *res = mem_alloc(sizeof(struct FunBody));
   res->localfundef = localfundef;
   res->stmtlist = stmtlist;
   res->vardec = vardec;
   return res;
}


