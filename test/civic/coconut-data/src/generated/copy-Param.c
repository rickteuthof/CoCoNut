// Hash: 31ba4afd09094183d749087a75279dea
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Param.h"
#include "generated/ast-Param.h"

struct Param;
struct Param *_copy_Param(struct Param *, imap_t *);
#include <string.h>
struct Param *_copy_Param(struct Param *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Param *res = mem_alloc(sizeof(struct Param));
    imap_insert(imap, node, res);
    res->next = _copy_Param(node->next, imap);
    if (res->id) {
         res->id = strdup(node->id);
    } else {
         res->id = NULL;
    }
    res->type = node->type;
    return res;
}

struct Param *copy_Param(struct Param *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Param * res = _copy_Param(node, imap);
    imap_free(imap);
    return res;
}

