// Hash: da1486863569ad210a4555708de59ea2
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-Decls.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;

void _CCNtrav_FunDef(struct FunDef *node, struct Info *info);
void _CCNtrav_GlobalDec(struct GlobalDec *node, struct Info *info);
void _CCNtrav_GlobalDef(struct GlobalDef *node, struct Info *info);
void _CCNtrav_Decls(struct Decls *node, struct Info *info);

void CCNtrav_Decls_decl(Decls *node, struct Info *info) {
    node->decl = _CCNtrav_Decl(node->decl, info);
}

void CCNtrav_Decls_next(Decls *node, struct Info *info) {
    node->next = _CCNtrav_Decls(node->next, info);
}

Decls *_CCNtrav_Decls(Decls *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    default:
        CCNtrav_Decls_decl(node, info);
        CCNtrav_Decls_next(node, info);
        break;
    }
    return node;
}

void replace_Decls(struct Decls *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_Decls;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_Decls: Not making a node replacement, since another replacement function was already called previously.");
    }
}

