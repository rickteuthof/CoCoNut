// Hash: a1b06fb9abb037787acc985178482577
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Decl.h"
#include "generated/ast-Decl.h"

struct FunDef *_copy_FunDef(struct FunDef *, imap_t *);
struct GlobalDec *_copy_GlobalDec(struct GlobalDec *, imap_t *);
struct GlobalDef *_copy_GlobalDef(struct GlobalDef *, imap_t *);

struct Decl *_copy_Decl(struct Decl *nodeset, imap_t *imap) {
    struct Decl *res = mem_alloc(sizeof(struct Decl));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Decl_FunDef:
            res->value.val_FunDef = _copy_FunDef(nodeset->value.val_FunDef, imap);
            break;
        case NS_Decl_GlobalDec:
            res->value.val_GlobalDec = _copy_GlobalDec(nodeset->value.val_GlobalDec, imap);
            break;
        case NS_Decl_GlobalDef:
            res->value.val_GlobalDef = _copy_GlobalDef(nodeset->value.val_GlobalDef, imap);
            break;
    }
    return res;
}

struct Decl *copy_Decl(struct Decl *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Decl * res = _copy_Decl(nodeset, imap);
    imap_free(imap);
    return res;
}

