// Hash: b42c3d81e8cab965bf25d8b307a365f2
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Cast.h"
#include "generated/ast-Cast.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Cast *_copy_Cast(struct Cast *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Cast *res = mem_alloc(sizeof(struct Cast));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    res->type = node->type;
    return res;
}

struct Cast *copy_Cast(struct Cast *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Cast * res = _copy_Cast(node, imap);
    imap_free(imap);
    return res;
}

