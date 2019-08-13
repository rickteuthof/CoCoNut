// Hash: c25846fd3a15b982bb7497256c83a575
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunSymbol.h"
#include "generated/ast-FunSymbol.h"

struct FunSymbol;
struct FunSymbol *_copy_FunSymbol(struct FunSymbol *, imap_t *);
#include <string.h>
struct FunSymbol *_copy_FunSymbol(struct FunSymbol *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FunSymbol *res = mem_alloc(sizeof(struct FunSymbol));
    imap_insert(imap, node, res);
    res->next = _copy_FunSymbol(node->next, imap);
    res->arity = node->arity;
    res->export = node->export;
    res->external = node->external;
    if (res->name) {
         res->name = strdup(node->name);
    } else {
         res->name = NULL;
    }
    res->offset = node->offset;
    res->scope = node->scope;
    if (res->scopedname) {
         res->scopedname = strdup(node->scopedname);
    } else {
         res->scopedname = NULL;
    }
    return res;
}

struct FunSymbol *copy_FunSymbol(struct FunSymbol *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FunSymbol * res = _copy_FunSymbol(node, imap);
    imap_free(imap);
    return res;
}

