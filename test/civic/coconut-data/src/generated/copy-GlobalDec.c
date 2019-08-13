// Hash: d370e4383f7aab78470bbb20eac500e8
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-GlobalDec.h"
#include "generated/ast-GlobalDec.h"

#include <string.h>
struct GlobalDec *_copy_GlobalDec(struct GlobalDec *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct GlobalDec *res = mem_alloc(sizeof(struct GlobalDec));
    imap_insert(imap, node, res);
    if (res->id) {
         res->id = strdup(node->id);
    } else {
         res->id = NULL;
    }
    res->type = node->type;
    return res;
}

struct GlobalDec *copy_GlobalDec(struct GlobalDec *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct GlobalDec * res = _copy_GlobalDec(node, imap);
    imap_free(imap);
    return res;
}

