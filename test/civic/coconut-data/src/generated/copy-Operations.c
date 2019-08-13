// Hash: 1604aaf06d8e16acccd979c8275f8e32
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Operations.h"
#include "generated/ast-Operations.h"

struct BinOp *_copy_BinOp(struct BinOp *, imap_t *);
struct MonOp *_copy_MonOp(struct MonOp *, imap_t *);

struct Operations *_copy_Operations(struct Operations *nodeset, imap_t *imap) {
    struct Operations *res = mem_alloc(sizeof(struct Operations));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Operations_BinOp:
            res->value.val_BinOp = _copy_BinOp(nodeset->value.val_BinOp, imap);
            break;
        case NS_Operations_MonOp:
            res->value.val_MonOp = _copy_MonOp(nodeset->value.val_MonOp, imap);
            break;
    }
    return res;
}

struct Operations *copy_Operations(struct Operations *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Operations * res = _copy_Operations(nodeset, imap);
    imap_free(imap);
    return res;
}

