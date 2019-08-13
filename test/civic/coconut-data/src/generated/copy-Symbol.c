// Hash: 2a17d582c98658539abe0f791e2036ae
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Symbol.h"
#include "generated/ast-Symbol.h"

struct Symbol;
struct Symbol *_copy_Symbol(struct Symbol *, imap_t *);
#include <string.h>
struct Symbol *_copy_Symbol(struct Symbol *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Symbol *res = mem_alloc(sizeof(struct Symbol));
    imap_insert(imap, node, res);
    res->next = _copy_Symbol(node->next, imap);
    res->export = node->export;
    res->external = node->external;
    if (res->name) {
         res->name = strdup(node->name);
    } else {
         res->name = NULL;
    }
    res->offset = node->offset;
    res->scope = node->scope;
    return res;
}

struct Symbol *copy_Symbol(struct Symbol *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Symbol * res = _copy_Symbol(node, imap);
    imap_free(imap);
    return res;
}

