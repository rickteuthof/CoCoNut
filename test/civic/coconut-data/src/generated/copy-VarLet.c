// Hash: 1fabc23d00d09394712ebc11a0e33a24
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-VarLet.h"
#include "generated/ast-VarLet.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Symbol;
#include <string.h>
struct VarLet *_copy_VarLet(struct VarLet *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct VarLet *res = mem_alloc(sizeof(struct VarLet));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
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

struct VarLet *copy_VarLet(struct VarLet *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct VarLet * res = _copy_VarLet(node, imap);
    imap_free(imap);
    return res;
}

