// Hash: e88afa1e610a0d88acf5ce24ec97f504
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-IntConst.h"
#include "generated/ast-IntConst.h"

struct IntConst *_copy_IntConst(struct IntConst *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct IntConst *res = mem_alloc(sizeof(struct IntConst));
    imap_insert(imap, node, res);
    res->value = node->value;
    return res;
}

struct IntConst *copy_IntConst(struct IntConst *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct IntConst * res = _copy_IntConst(node, imap);
    imap_free(imap);
    return res;
}

