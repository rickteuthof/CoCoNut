// Hash: cc2abd438fff2facf1c543ad95507122
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunCall.h"
#include "generated/ast-FunCall.h"

struct ExprList;
struct ExprList *_copy_ExprList(struct ExprList *, imap_t *);
struct FunSymbol;
#include <string.h>
struct FunCall *_copy_FunCall(struct FunCall *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FunCall *res = mem_alloc(sizeof(struct FunCall));
    imap_insert(imap, node, res);
    res->params = _copy_ExprList(node->params, imap);
    if (res->id) {
         res->id = strdup(node->id);
    } else {
         res->id = NULL;
    }
    // If link is copied, use copy and check for NULL
    if (res->symbol) {
         struct FunSymbol *copy = imap_retrieve(imap, node->symbol);
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

struct FunCall *copy_FunCall(struct FunCall *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FunCall * res = _copy_FunCall(node, imap);
    imap_free(imap);
    return res;
}

