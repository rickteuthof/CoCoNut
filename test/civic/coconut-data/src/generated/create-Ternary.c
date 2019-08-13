// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#include "lib/memory.h"
#include "generated/ast-Ternary.h"
// ast-Ternary.h includes the neccesary attribute and children.
struct Ternary *create_Ternary(
       struct Expr *falseexpr,
       struct Expr *testexpr,
       struct Expr *trueexpr) {
   struct Ternary *res = mem_alloc(sizeof(struct Ternary));
   res->falseexpr = falseexpr;
   res->testexpr = testexpr;
   res->trueexpr = trueexpr;
   return res;
}


