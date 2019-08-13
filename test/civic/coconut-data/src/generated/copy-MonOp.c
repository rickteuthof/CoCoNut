// Hash: b0bfe9d720169c1396aafc91b36ae925
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-MonOp.h"
#include "generated/ast-MonOp.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct MonOp *_copy_MonOp(struct MonOp *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct MonOp *res = mem_alloc(sizeof(struct MonOp));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    res->op = node->op;
    return res;
}

struct MonOp *copy_MonOp(struct MonOp *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct MonOp * res = _copy_MonOp(node, imap);
    imap_free(imap);
    return res;
}

