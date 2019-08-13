// Hash: 0624d4152c0617b22ca17c7560e5b107
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-ExprList.h"
#include "generated/ast-ExprList.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct ExprList;
struct ExprList *_copy_ExprList(struct ExprList *, imap_t *);
struct ExprList *_copy_ExprList(struct ExprList *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct ExprList *res = mem_alloc(sizeof(struct ExprList));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    res->next = _copy_ExprList(node->next, imap);
    return res;
}

struct ExprList *copy_ExprList(struct ExprList *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct ExprList * res = _copy_ExprList(node, imap);
    imap_free(imap);
    return res;
}

