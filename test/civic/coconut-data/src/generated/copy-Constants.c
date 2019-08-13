// Hash: be4c521ad82189ec8e08be8055ccee09
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Constants.h"
#include "generated/ast-Constants.h"

struct BoolConst *_copy_BoolConst(struct BoolConst *, imap_t *);
struct FloatConst *_copy_FloatConst(struct FloatConst *, imap_t *);
struct IntConst *_copy_IntConst(struct IntConst *, imap_t *);

struct Constants *_copy_Constants(struct Constants *nodeset, imap_t *imap) {
    struct Constants *res = mem_alloc(sizeof(struct Constants));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Constants_BoolConst:
            res->value.val_BoolConst = _copy_BoolConst(nodeset->value.val_BoolConst, imap);
            break;
        case NS_Constants_FloatConst:
            res->value.val_FloatConst = _copy_FloatConst(nodeset->value.val_FloatConst, imap);
            break;
        case NS_Constants_IntConst:
            res->value.val_IntConst = _copy_IntConst(nodeset->value.val_IntConst, imap);
            break;
    }
    return res;
}

struct Constants *copy_Constants(struct Constants *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Constants * res = _copy_Constants(nodeset, imap);
    imap_free(imap);
    return res;
}

