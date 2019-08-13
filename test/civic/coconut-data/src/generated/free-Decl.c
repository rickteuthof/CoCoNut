// Hash: a1b06fb9abb037787acc985178482577
#include "generated/free-Decl.h"

#include "generated/free-FunDef.h"
#include "generated/free-GlobalDec.h"
#include "generated/free-GlobalDef.h"
void free_Decl_tree(struct Decl *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Decl_FunDef:
        free_FunDef_tree(nodeset->value.val_FunDef);
        break;
    case NS_Decl_GlobalDec:
        free_GlobalDec_tree(nodeset->value.val_GlobalDec);
        break;
    case NS_Decl_GlobalDef:
        free_GlobalDef_tree(nodeset->value.val_GlobalDef);
        break;
    }
    mem_free(nodeset);
}
void free_Decl_node(struct Decl* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Decl_FunDef:
        free_FunDef_node(nodeset->value.val_FunDef);
        break;
    case NS_Decl_GlobalDec:
        free_GlobalDec_node(nodeset->value.val_GlobalDec);
        break;
    case NS_Decl_GlobalDef:
        free_GlobalDef_node(nodeset->value.val_GlobalDef);
        break;
    }
    mem_free(nodeset);
}

