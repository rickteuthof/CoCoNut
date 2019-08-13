// Hash: be4c521ad82189ec8e08be8055ccee09
#include "generated/free-Constants.h"

#include "generated/free-BoolConst.h"
#include "generated/free-FloatConst.h"
#include "generated/free-IntConst.h"
void free_Constants_tree(struct Constants *nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Constants_BoolConst:
        free_BoolConst_tree(nodeset->value.val_BoolConst);
        break;
    case NS_Constants_FloatConst:
        free_FloatConst_tree(nodeset->value.val_FloatConst);
        break;
    case NS_Constants_IntConst:
        free_IntConst_tree(nodeset->value.val_IntConst);
        break;
    }
    mem_free(nodeset);
}
void free_Constants_node(struct Constants* nodeset) {
    if (nodeset == NULL) {
        return;
    }

    switch(nodeset->type) {
    case NS_Constants_BoolConst:
        free_BoolConst_node(nodeset->value.val_BoolConst);
        break;
    case NS_Constants_FloatConst:
        free_FloatConst_node(nodeset->value.val_FloatConst);
        break;
    case NS_Constants_IntConst:
        free_IntConst_node(nodeset->value.val_IntConst);
        break;
    }
    mem_free(nodeset);
}

