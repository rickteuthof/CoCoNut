// Hash: 33e19f933fee95125167d08907d344d2
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-FunHeader.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_Param(struct Param *node, struct Info *info);

void CCNtrav_FunHeader_params(FunHeader *node, struct Info *info) {
    node->params = _CCNtrav_Param(node->params, info);
}

FunHeader *_CCNtrav_FunHeader(FunHeader *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Refactor:
        break;
    case TRAV_RenameFor:
        break;
    case TRAV_SplitInit:
        break;
    case TRAV_Symbols:
        break;
    case TRAV_TypeCheck:
        return TypeCheck_FunHeader(node, info);;
    default:
        CCNtrav_FunHeader_params(node, info);
        break;
    }
    return node;
}

void replace_FunHeader(struct FunHeader *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_FunHeader;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_FunHeader: Not making a node replacement, since another replacement function was already called previously.");
    }
}

