// Hash: 514d9d5eed2b7d56245866708d0e1d89
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-BinOp.h"
#include "generated/ast-BinOp.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct BinOp *_copy_BinOp(struct BinOp *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct BinOp *res = mem_alloc(sizeof(struct BinOp));
    imap_insert(imap, node, res);
    res->left = _copy_Expr(node->left, imap);
    res->right = _copy_Expr(node->right, imap);
    res->op = node->op;
    return res;
}

struct BinOp *copy_BinOp(struct BinOp *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct BinOp * res = _copy_BinOp(node, imap);
    imap_free(imap);
    return res;
}

