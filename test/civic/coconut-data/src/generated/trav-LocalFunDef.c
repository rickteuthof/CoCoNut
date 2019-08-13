// Hash: 335492ed82f8520c39ccbce6a5739af7
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-LocalFunDef.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_FunDef(struct FunDef *node, struct Info *info);
void _CCNtrav_LocalFunDef(struct LocalFunDef *node, struct Info *info);

void CCNtrav_LocalFunDef_decl(LocalFunDef *node, struct Info *info) {
    node->decl = _CCNtrav_FunDef(node->decl, info);
}

void CCNtrav_LocalFunDef_next(LocalFunDef *node, struct Info *info) {
    node->next = _CCNtrav_LocalFunDef(node->next, info);
}

LocalFunDef *_CCNtrav_LocalFunDef(LocalFunDef *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    default:
        CCNtrav_LocalFunDef_decl(node, info);
        CCNtrav_LocalFunDef_next(node, info);
        break;
    }
    return node;
}

void replace_LocalFunDef(struct LocalFunDef *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_LocalFunDef;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_LocalFunDef: Not making a node replacement, since another replacement function was already called previously.");
    }
}

