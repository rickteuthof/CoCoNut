// Hash: 70eba40e9dab0c2491717f2637a08068
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Root.h"
#include "generated/ast-Root.h"

struct Decls;
struct Decls *_copy_Decls(struct Decls *, imap_t *);
struct FunSymbol;
struct FunSymbol *_copy_FunSymbol(struct FunSymbol *, imap_t *);
struct Symbol;
struct Symbol *_copy_Symbol(struct Symbol *, imap_t *);
struct Root *_copy_Root(struct Root *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Root *res = mem_alloc(sizeof(struct Root));
    imap_insert(imap, node, res);
    res->decls = _copy_Decls(node->decls, imap);
    res->funsymbol = _copy_FunSymbol(node->funsymbol, imap);
    res->symbol = _copy_Symbol(node->symbol, imap);
    return res;
}

struct Root *copy_Root(struct Root *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Root * res = _copy_Root(node, imap);
    imap_free(imap);
    return res;
}

