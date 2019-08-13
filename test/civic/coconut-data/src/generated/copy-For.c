// Hash: 1b5e131a901dfeb50ab1b084b4472381
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-For.h"
#include "generated/ast-For.h"

struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Symbol;
#include <string.h>
struct For *_copy_For(struct For *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct For *res = mem_alloc(sizeof(struct For));
    imap_insert(imap, node, res);
    res->block = _copy_StmtList(node->block, imap);
    res->boundexpr = _copy_Expr(node->boundexpr, imap);
    res->initexpr = _copy_Expr(node->initexpr, imap);
    res->stepexpr = _copy_Expr(node->stepexpr, imap);
    if (res->id) {
         res->id = strdup(node->id);
    } else {
         res->id = NULL;
    }
    // If link is copied, use copy and check for NULL
    if (res->symbol) {
         struct Symbol *copy = imap_retrieve(imap, node->symbol);
         if (copy) {
             res->symbol = copy;
         } else {
             res->symbol = node->symbol;
         }
    } else {
         res->symbol = NULL;
    }
    return res;
}

struct For *copy_For(struct For *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct For * res = _copy_For(node, imap);
    imap_free(imap);
    return res;
}

