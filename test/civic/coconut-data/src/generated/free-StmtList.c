// Hash: af28c29a686569d7ebb3c15611b384d2
#include "generated/free-StmtList.h"

#include "generated/free-StmtList.h"
#include "generated/free-Stmt.h"
void free_StmtList_tree(struct StmtList* node) {
    if (node == NULL) {
        return;
    }

    free_StmtList_tree(node->next);
    free_Stmt_tree(node->stmt);
    mem_free(node);
}
void free_StmtList_node(struct StmtList* node) {
 // skip children.
    mem_free(node);
}

