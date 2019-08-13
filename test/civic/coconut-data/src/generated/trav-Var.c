// Hash: 121eeb949095a740dd78338f981bac61
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Var.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;


Var *_CCNtrav_Var(Var *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_Var(node, info);;
    case TRAV_Refactor:
        return Refactor_Var(node, info);;
    case TRAV_RenameFor:
        return RenameFor_Var(node, info);;
    case TRAV_TypeCheck:
        return TypeCheck_Var(node, info);;
    default:
        break;
    }
    return node;
}

void replace_Var(struct Var *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Var;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Var: Not making a node replacement, since another replacement function was already called previously.");
    }
}

