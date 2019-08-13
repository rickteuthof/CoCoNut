// Hash: af28c29a686569d7ebb3c15611b384d2
#include "lib/memory.h"
#include "generated/ast-StmtList.h"
// ast-StmtList.h includes the neccesary attribute and children.
struct StmtList *create_StmtList(
       struct StmtList *next,
       struct Stmt *stmt) {
   struct StmtList *res = mem_alloc(sizeof(struct StmtList));
   res->next = next;
   res->stmt = stmt;
   return res;
}


