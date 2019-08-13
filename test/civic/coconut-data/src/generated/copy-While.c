// Hash: df86d0e15495f375db62ae5bf23c0be7
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-While.h"
#include "generated/ast-While.h"

struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct While *_copy_While(struct While *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct While *res = mem_alloc(sizeof(struct While));
    imap_insert(imap, node, res);
    res->block = _copy_StmtList(node->block, imap);
    res->condition = _copy_Expr(node->condition, imap);
    return res;
}

struct While *copy_While(struct While *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct While * res = _copy_While(node, imap);
    imap_free(imap);
    return res;
}

