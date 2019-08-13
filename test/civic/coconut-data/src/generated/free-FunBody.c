// Hash: b749bf704b901788bcd7cb60caea2822
#include "generated/free-FunBody.h"

#include "generated/free-LocalFunDef.h"
#include "generated/free-StmtList.h"
#include "generated/free-VarDec.h"
void free_FunBody_tree(struct FunBody* node) {
    if (node == NULL) {
        return;
    }

    free_LocalFunDef_tree(node->localfundef);
    free_StmtList_tree(node->stmtlist);
    free_VarDec_tree(node->vardec);
    mem_free(node);
}
void free_FunBody_node(struct FunBody* node) {
 // skip children.
    mem_free(node);
}

