// Hash: 31ba4afd09094183d749087a75279dea
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Param.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_Param(struct Param *node, struct Info *info);

void CCNtrav_Param_next(Param *node, struct Info *info) {
    node->next = _CCNtrav_Param(node->next, info);
}

Param *_CCNtrav_Param(Param *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_Param(node, info);;
    case TRAV_Refactor:
        break;
    case TRAV_RenameFor:
        break;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_Param(node, info);;
    default:
        CCNtrav_Param_next(node, info);
        break;
    }
    return node;
}

void replace_Param(struct Param *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Param;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Param: Not making a node replacement, since another replacement function was already called previously.");
    }
}

