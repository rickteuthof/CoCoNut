// Hash: e7edc9c998e6633c941feaada999a32e
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Vars.h"
#include "generated/ast-Vars.h"

struct Var *_copy_Var(struct Var *, imap_t *);
struct VarDec *_copy_VarDec(struct VarDec *, imap_t *);
struct VarLet *_copy_VarLet(struct VarLet *, imap_t *);

struct Vars *_copy_Vars(struct Vars *nodeset, imap_t *imap) {
    struct Vars *res = mem_alloc(sizeof(struct Vars));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Vars_Var:
            res->value.val_Var = _copy_Var(nodeset->value.val_Var, imap);
            break;
        case NS_Vars_VarDec:
            res->value.val_VarDec = _copy_VarDec(nodeset->value.val_VarDec, imap);
            break;
        case NS_Vars_VarLet:
            res->value.val_VarLet = _copy_VarLet(nodeset->value.val_VarLet, imap);
            break;
    }
    return res;
}

struct Vars *copy_Vars(struct Vars *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Vars * res = _copy_Vars(nodeset, imap);
    imap_free(imap);
    return res;
}

