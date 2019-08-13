// Hash: 514d9d5eed2b7d56245866708d0e1d89
#include "lib/memory.h"
#include "generated/ast-BinOp.h"
// ast-BinOp.h includes the neccesary attribute and children.
struct BinOp *create_BinOp(
       struct Expr *left,
       struct Expr *right,
       BinOpEnum op) {
   struct BinOp *res = mem_alloc(sizeof(struct BinOp));
   res->left = left;
   res->right = right;
   res->op = op;
   return res;
}


