// Hash: 33e19f933fee95125167d08907d344d2
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunHeader.h"
#include "generated/ast-FunHeader.h"

struct Param;
struct Param *_copy_Param(struct Param *, imap_t *);
#include <string.h>
struct FunHeader *_copy_FunHeader(struct FunHeader *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FunHeader *res = mem_alloc(sizeof(struct FunHeader));
    imap_insert(imap, node, res);
    res->params = _copy_Param(node->params, imap);
    if (res->id) {
         res->id = strdup(node->id);
    } else {
         res->id = NULL;
    }
    res->rettype = node->rettype;
    return res;
}

struct FunHeader *copy_FunHeader(struct FunHeader *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FunHeader * res = _copy_FunHeader(node, imap);
    imap_free(imap);
    return res;
}

