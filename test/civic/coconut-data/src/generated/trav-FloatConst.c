// Hash: e53f745fb8225fc8c2f64b87c6517cb3
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FloatConst.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;


FloatConst *_CCNtrav_FloatConst(FloatConst *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        return Refactor_FloatConst(node, info);;
    case TRAV_TypeCheck:
        return TypeCheck_FloatConst(node, info);;
    default:
        break;
    }
    return node;
}

void replace_FloatConst(struct FloatConst *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FloatConst;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FloatConst: Not making a node replacement, since another replacement function was already called previously.");
    }
}

