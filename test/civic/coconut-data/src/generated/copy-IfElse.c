// Hash: 49a6200318f4e38dbef3daba45e4ce7b
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-IfElse.h"
#include "generated/ast-IfElse.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct IfElse *_copy_IfElse(struct IfElse *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct IfElse *res = mem_alloc(sizeof(struct IfElse));
    imap_insert(imap, node, res);
    res->condition = _copy_Expr(node->condition, imap);
    res->elseblock = _copy_StmtList(node->elseblock, imap);
    res->ifblock = _copy_StmtList(node->ifblock, imap);
    return res;
}

struct IfElse *copy_IfElse(struct IfElse *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct IfElse * res = _copy_IfElse(node, imap);
    imap_free(imap);
    return res;
}

