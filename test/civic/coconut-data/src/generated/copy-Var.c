// Hash: 121eeb949095a740dd78338f981bac61
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Var.h"
#include "generated/ast-Var.h"

struct Symbol;
#include <string.h>
struct Var *_copy_Var(struct Var *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Var *res = mem_alloc(sizeof(struct Var));
    imap_insert(imap, node, res);
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

struct Var *copy_Var(struct Var *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Var * res = _copy_Var(node, imap);
    imap_free(imap);
    return res;
}

