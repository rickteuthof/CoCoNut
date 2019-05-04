#include "generated/traversal-FindFundefFromRoot.h"
#include "generated/ast.h"
#include <stddef.h>
#include <stdio.h>

struct Info {int a;};

Info *FindFundefFromRoot_createinfo(void) {
    return NULL;
}

void FindFundefFromRoot_freeinfo(Info *l) {
    
}

void FindFundefFromRoot_FunDef(FunDef *node, Info *info) {
    printf("ARRIVED!\n");
}
