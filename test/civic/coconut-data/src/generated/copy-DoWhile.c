// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-DoWhile.h"
#include "generated/ast-DoWhile.h"

struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct DoWhile *_copy_DoWhile(struct DoWhile *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct DoWhile *res = mem_alloc(sizeof(struct DoWhile));
    imap_insert(imap, node, res);
    res->block = _copy_StmtList(node->block, imap);
    res->condition = _copy_Expr(node->condition, imap);
    return res;
}

struct DoWhile *copy_DoWhile(struct DoWhile *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct DoWhile * res = _copy_DoWhile(node, imap);
    imap_free(imap);
    return res;
}

