// Hash: 3e39a0cd59728ac5797ddd72e5100164
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-VarDec.h"
#include "generated/ast-VarDec.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct VarDec;
struct VarDec *_copy_VarDec(struct VarDec *, imap_t *);
struct Symbol;
#include <string.h>
struct VarDec *_copy_VarDec(struct VarDec *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct VarDec *res = mem_alloc(sizeof(struct VarDec));
    imap_insert(imap, node, res);
    res->expr = _copy_Expr(node->expr, imap);
    res->next = _copy_VarDec(node->next, imap);
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

struct VarDec *copy_VarDec(struct VarDec *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct VarDec * res = _copy_VarDec(node, imap);
    imap_free(imap);
    return res;
}

