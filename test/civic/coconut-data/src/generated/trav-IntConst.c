// Hash: e88afa1e610a0d88acf5ce24ec97f504
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-IntConst.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;


IntConst *_CCNtrav_IntConst(IntConst *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_IntConst(node, info);;
    case TRAV_TypeCheck:
        return TypeCheck_IntConst(node, info);;
    default:
        break;
    }
    return node;
}

void replace_IntConst(struct IntConst *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_IntConst;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_IntConst: Not making a node replacement, since another replacement function was already called previously.");
    }
}

