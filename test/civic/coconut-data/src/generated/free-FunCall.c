// Hash: cc2abd438fff2facf1c543ad95507122
#include "generated/free-FunCall.h"

#include "generated/free-ExprList.h"
void free_FunCall_tree(struct FunCall* node) {
    if (node == NULL) {
        return;
    }

    free_ExprList_tree(node->params);
    mem_free(node->id);
    mem_free(node);
}
void free_FunCall_node(struct FunCall* node) {
 // skip children.
    mem_free(node->id);
    mem_free(node);
}

