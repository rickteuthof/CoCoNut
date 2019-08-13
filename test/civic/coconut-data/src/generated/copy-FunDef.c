// Hash: 1e4fc8c57864026894e956f2ce63ce36
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunDef.h"
#include "generated/ast-FunDef.h"

struct FunBody;
struct FunBody *_copy_FunBody(struct FunBody *, imap_t *);
struct FunHeader;
struct FunHeader *_copy_FunHeader(struct FunHeader *, imap_t *);
struct FunSymbol;
struct FunSymbol *_copy_FunSymbol(struct FunSymbol *, imap_t *);
struct FunDef;
struct FunDef *_copy_FunDef(struct FunDef *, imap_t *);
struct Symbol;
struct Symbol *_copy_Symbol(struct Symbol *, imap_t *);
struct FunDef *_copy_FunDef(struct FunDef *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FunDef *res = mem_alloc(sizeof(struct FunDef));
    imap_insert(imap, node, res);
    res->funbody = _copy_FunBody(node->funbody, imap);
    res->funheader = _copy_FunHeader(node->funheader, imap);
    res->funsymbol = _copy_FunSymbol(node->funsymbol, imap);
    res->next = _copy_FunDef(node->next, imap);
    res->symbol = _copy_Symbol(node->symbol, imap);
    res->export = node->export;
    res->external = node->external;
    return res;
}

struct FunDef *copy_FunDef(struct FunDef *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FunDef * res = _copy_FunDef(node, imap);
    imap_free(imap);
    return res;
}

