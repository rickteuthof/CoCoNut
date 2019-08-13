// Hash: 657816c98ab8bae4509f890a4cf4b654
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-BoolConst.h"
#include "generated/ast-BoolConst.h"

struct BoolConst *_copy_BoolConst(struct BoolConst *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct BoolConst *res = mem_alloc(sizeof(struct BoolConst));
    imap_insert(imap, node, res);
    res->value = node->value;
    return res;
}

struct BoolConst *copy_BoolConst(struct BoolConst *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct BoolConst * res = _copy_BoolConst(node, imap);
    imap_free(imap);
    return res;
}

