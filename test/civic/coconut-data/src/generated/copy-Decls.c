// Hash: da1486863569ad210a4555708de59ea2
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Decls.h"
#include "generated/ast-Decls.h"

struct Decl;
struct Decl *_copy_Decl(struct Decl *, imap_t *);
struct Decls;
struct Decls *_copy_Decls(struct Decls *, imap_t *);
struct Decls *_copy_Decls(struct Decls *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Decls *res = mem_alloc(sizeof(struct Decls));
    imap_insert(imap, node, res);
    res->decl = _copy_Decl(node->decl, imap);
    res->next = _copy_Decls(node->next, imap);
    return res;
}

struct Decls *copy_Decls(struct Decls *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Decls * res = _copy_Decls(node, imap);
    imap_free(imap);
    return res;
}

