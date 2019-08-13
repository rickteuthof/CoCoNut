// Hash: 782f9b0b6daa7e2b74e6825788ce728f
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunctionParts.h"
#include "generated/ast-FunctionParts.h"

struct FunBody *_copy_FunBody(struct FunBody *, imap_t *);
struct FunDef *_copy_FunDef(struct FunDef *, imap_t *);
struct FunHeader *_copy_FunHeader(struct FunHeader *, imap_t *);
struct Param *_copy_Param(struct Param *, imap_t *);

struct FunctionParts *_copy_FunctionParts(struct FunctionParts *nodeset, imap_t *imap) {
    struct FunctionParts *res = mem_alloc(sizeof(struct FunctionParts));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_FunctionParts_FunBody:
            res->value.val_FunBody = _copy_FunBody(nodeset->value.val_FunBody, imap);
            break;
        case NS_FunctionParts_FunDef:
            res->value.val_FunDef = _copy_FunDef(nodeset->value.val_FunDef, imap);
            break;
        case NS_FunctionParts_FunHeader:
            res->value.val_FunHeader = _copy_FunHeader(nodeset->value.val_FunHeader, imap);
            break;
        case NS_FunctionParts_Param:
            res->value.val_Param = _copy_Param(nodeset->value.val_Param, imap);
            break;
    }
    return res;
}

struct FunctionParts *copy_FunctionParts(struct FunctionParts *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct FunctionParts * res = _copy_FunctionParts(nodeset, imap);
    imap_free(imap);
    return res;
}

