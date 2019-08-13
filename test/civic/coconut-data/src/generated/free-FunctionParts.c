// Hash: 782f9b0b6daa7e2b74e6825788ce728f
#include "generated/free-FunctionParts.h"

#include "generated/free-FunBody.h"
#include "generated/free-FunDef.h"
#include "generated/free-FunHeader.h"
#include "generated/free-Param.h"
void free_FunctionParts_tree(struct FunctionParts *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_FunctionParts_FunBody:
        free_FunBody_tree(nodeset->value.val_FunBody);
        break;
    case NS_FunctionParts_FunDef:
        free_FunDef_tree(nodeset->value.val_FunDef);
        break;
    case NS_FunctionParts_FunHeader:
        free_FunHeader_tree(nodeset->value.val_FunHeader);
        break;
    case NS_FunctionParts_Param:
        free_Param_tree(nodeset->value.val_Param);
        break;
    }
    mem_free(nodeset);
}
void free_FunctionParts_node(struct FunctionParts* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_FunctionParts_FunBody:
        free_FunBody_node(nodeset->value.val_FunBody);
        break;
    case NS_FunctionParts_FunDef:
        free_FunDef_node(nodeset->value.val_FunDef);
        break;
    case NS_FunctionParts_FunHeader:
        free_FunHeader_node(nodeset->value.val_FunHeader);
        break;
    case NS_FunctionParts_Param:
        free_Param_node(nodeset->value.val_Param);
        break;
    }
    mem_free(nodeset);
}

