// Hash: d370e4383f7aab78470bbb20eac500e8
#include <stdio.h>
#include "lib/print.h"
#include "generated/trav-GlobalDec.h"
// generated/trav-core.h is included by my header.
extern NodeType node_replacement_type;
extern void *node_replacement;


GlobalDec *_CCNtrav_GlobalDec(GlobalDec *node, struct Info *info) {
    if (!node) return node;
    switch (CCNtrav_current())) {
    case TRAV_Context:
        return Context_GlobalDec(node, info);;
    default:
        break;
    }
    return node;
}

void replace_GlobalDec(struct GlobalDec *node) {
    if (node_replacement == NULL) {
        node_replacement_type = NT_GlobalDec;
        node_replacement = node;
    } else {
        print_user_error("traversal-driver", "replace_GlobalDec: Not making a node replacement, since another replacement function was already called previously.");
    }
}

