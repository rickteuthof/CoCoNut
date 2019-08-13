// Hash: 657816c98ab8bae4509f890a4cf4b654
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-BoolConst.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;


BoolConst *_CCNtrav_BoolConst(BoolConst *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_BoolConst(node, info);;
    case TRAV_TypeCheck:
        return TypeCheck_BoolConst(node, info);;
    default:
        break;
    }
    return node;
}

void replace_BoolConst(struct BoolConst *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_BoolConst;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_BoolConst: Not making a node replacement, since another replacement function was already called previously.");
    }
}

