// Hash: 47bbee1cc9f9bf097e4833f85bb45167
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-GlobalDef.h"
#include "generated/ast-GlobalDef.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Symbol;
#include <string.h>
struct GlobalDef *_copy_GlobalDef(struct GlobalDef *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct GlobalDef *res = mem_alloc(sizeof(struct GlobalDef));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    res->export = node->export;
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
    res->type = node->type;
    return res;
}

struct GlobalDef *copy_GlobalDef(struct GlobalDef *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct GlobalDef * res = _copy_GlobalDef(node, imap);
    imap_free(imap);
    return res;
}

