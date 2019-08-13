// Hash: e7edc9c998e6633c941feaada999a32e
#include "generated/free-Vars.h"

#include "generated/free-Var.h"
#include "generated/free-VarDec.h"
#include "generated/free-VarLet.h"
void free_Vars_tree(struct Vars *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Vars_Var:
        free_Var_tree(nodeset->value.val_Var);
        break;
    case NS_Vars_VarDec:
        free_VarDec_tree(nodeset->value.val_VarDec);
        break;
    case NS_Vars_VarLet:
        free_VarLet_tree(nodeset->value.val_VarLet);
        break;
    }
    mem_free(nodeset);
}
void free_Vars_node(struct Vars* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Vars_Var:
        free_Var_node(nodeset->value.val_Var);
        break;
    case NS_Vars_VarDec:
        free_VarDec_node(nodeset->value.val_VarDec);
        break;
    case NS_Vars_VarLet:
        free_VarLet_node(nodeset->value.val_VarLet);
        break;
    }
    mem_free(nodeset);
}

