// Hash: e53f745fb8225fc8c2f64b87c6517cb3
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FloatConst.h"
#include "generated/ast-FloatConst.h"

struct FloatConst *_copy_FloatConst(struct FloatConst *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FloatConst *res = mem_alloc(sizeof(struct FloatConst));
    imap_insert(imap, node, res);
    res->value = node->value;
    return res;
}

struct FloatConst *copy_FloatConst(struct FloatConst *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FloatConst * res = _copy_FloatConst(node, imap);
    imap_free(imap);
    return res;
}

