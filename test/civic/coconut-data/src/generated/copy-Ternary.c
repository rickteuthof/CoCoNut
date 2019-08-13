// Hash: 16b156e3bb9be8cca59ddae782f6cffa
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Ternary.h"
#include "generated/ast-Ternary.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *, imap_t *);
struct Ternary *_copy_Ternary(struct Ternary *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct Ternary *res = mem_alloc(sizeof(struct Ternary));
    imap_insert(imap, node, res);
    res->falseexpr = _copy_Expr(node->falseexpr, imap);
    res->testexpr = _copy_Expr(node->testexpr, imap);
    res->trueexpr = _copy_Expr(node->trueexpr, imap);
    return res;
}

struct Ternary *copy_Ternary(struct Ternary *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct Ternary * res = _copy_Ternary(node, imap);
    imap_free(imap);
    return res;
}

