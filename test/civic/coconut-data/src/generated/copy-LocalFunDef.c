// Hash: 335492ed82f8520c39ccbce6a5739af7
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-LocalFunDef.h"
#include "generated/ast-LocalFunDef.h"

struct FunDef;
struct FunDef *_copy_FunDef(struct FunDef *, imap_t *);
struct LocalFunDef;
struct LocalFunDef *_copy_LocalFunDef(struct LocalFunDef *, imap_t *);
struct LocalFunDef *_copy_LocalFunDef(struct LocalFunDef *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct LocalFunDef *res = mem_alloc(sizeof(struct LocalFunDef));
    imap_insert(imap, node, res);
    res->decl = _copy_FunDef(node->decl, imap);
    res->next = _copy_LocalFunDef(node->next, imap);
    return res;
}

struct LocalFunDef *copy_LocalFunDef(struct LocalFunDef *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct LocalFunDef * res = _copy_LocalFunDef(node, imap);
    imap_free(imap);
    return res;
}

