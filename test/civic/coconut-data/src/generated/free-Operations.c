// Hash: 1604aaf06d8e16acccd979c8275f8e32
#include "generated/free-Operations.h"

#include "generated/free-BinOp.h"
#include "generated/free-MonOp.h"
void free_Operations_tree(struct Operations *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Operations_BinOp:
        free_BinOp_tree(nodeset->value.val_BinOp);
        break;
    case NS_Operations_MonOp:
        free_MonOp_tree(nodeset->value.val_MonOp);
        break;
    }
    mem_free(nodeset);
}
void free_Operations_node(struct Operations* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Operations_BinOp:
        free_BinOp_node(nodeset->value.val_BinOp);
        break;
    case NS_Operations_MonOp:
        free_MonOp_node(nodeset->value.val_MonOp);
        break;
    }
    mem_free(nodeset);
}

