// Hash: 4b5f0f88bdd5355115a58de9c899d7b4
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Return.h"
#include "generated/ast-Return.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Return *_copy_Return(struct Return *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Return *res = mem_alloc(sizeof(struct Return));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    return res;
}

struct Return *copy_Return(struct Return *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Return * res = _copy_Return(node, imap);
    imap_free(imap);
    return res;
}

