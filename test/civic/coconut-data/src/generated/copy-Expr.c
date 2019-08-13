// Hash: 6d316f510e6ccaf4826835131137a57e
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Expr.h"
#include "generated/ast-Expr.h"

struct BinOp *_copy_BinOp(struct BinOp *, imap_t *);
struct BoolConst *_copy_BoolConst(struct BoolConst *, imap_t *);
struct Cast *_copy_Cast(struct Cast *, imap_t *);
struct FloatConst *_copy_FloatConst(struct FloatConst *, imap_t *);
struct FunCall *_copy_FunCall(struct FunCall *, imap_t *);
struct IntConst *_copy_IntConst(struct IntConst *, imap_t *);
struct MonOp *_copy_MonOp(struct MonOp *, imap_t *);
struct Ternary *_copy_Ternary(struct Ternary *, imap_t *);
struct Var *_copy_Var(struct Var *, imap_t *);

struct Expr *_copy_Expr(struct Expr *nodeset, imap_t *imap) {
    struct Expr *res = mem_alloc(sizeof(struct Expr));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Expr_BinOp:
            res->value.val_BinOp = _copy_BinOp(nodeset->value.val_BinOp, imap);
            break;
        case NS_Expr_BoolConst:
            res->value.val_BoolConst = _copy_BoolConst(nodeset->value.val_BoolConst, imap);
            break;
        case NS_Expr_Cast:
            res->value.val_Cast = _copy_Cast(nodeset->value.val_Cast, imap);
            break;
        case NS_Expr_FloatConst:
            res->value.val_FloatConst = _copy_FloatConst(nodeset->value.val_FloatConst, imap);
            break;
        case NS_Expr_FunCall:
            res->value.val_FunCall = _copy_FunCall(nodeset->value.val_FunCall, imap);
            break;
        case NS_Expr_IntConst:
            res->value.val_IntConst = _copy_IntConst(nodeset->value.val_IntConst, imap);
            break;
        case NS_Expr_MonOp:
            res->value.val_MonOp = _copy_MonOp(nodeset->value.val_MonOp, imap);
            break;
        case NS_Expr_Ternary:
            res->value.val_Ternary = _copy_Ternary(nodeset->value.val_Ternary, imap);
            break;
        case NS_Expr_Var:
            res->value.val_Var = _copy_Var(nodeset->value.val_Var, imap);
            break;
    }
    return res;
}

struct Expr *copy_Expr(struct Expr *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Expr * res = _copy_Expr(nodeset, imap);
    imap_free(imap);
    return res;
}

