// Hash: bb6639b82c8f18c2af9886944317b845
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-Stmt.h"
#include "generated/ast-Stmt.h"

struct DoWhile *_copy_DoWhile(struct DoWhile *, imap_t *);
struct For *_copy_For(struct For *, imap_t *);
struct FunCall *_copy_FunCall(struct FunCall *, imap_t *);
struct IfElse *_copy_IfElse(struct IfElse *, imap_t *);
struct Return *_copy_Return(struct Return *, imap_t *);
struct VarLet *_copy_VarLet(struct VarLet *, imap_t *);
struct While *_copy_While(struct While *, imap_t *);

struct Stmt *_copy_Stmt(struct Stmt *nodeset, imap_t *imap) {
    struct Stmt *res = mem_alloc(sizeof(struct Stmt));
    imap_insert(imap, nodeset, res);
    res->type = nodeset->type;
    switch (nodeset->type) {
        case NS_Stmt_DoWhile:
            res->value.val_DoWhile = _copy_DoWhile(nodeset->value.val_DoWhile, imap);
            break;
        case NS_Stmt_For:
            res->value.val_For = _copy_For(nodeset->value.val_For, imap);
            break;
        case NS_Stmt_FunCall:
            res->value.val_FunCall = _copy_FunCall(nodeset->value.val_FunCall, imap);
            break;
        case NS_Stmt_IfElse:
            res->value.val_IfElse = _copy_IfElse(nodeset->value.val_IfElse, imap);
            break;
        case NS_Stmt_Return:
            res->value.val_Return = _copy_Return(nodeset->value.val_Return, imap);
            break;
        case NS_Stmt_VarLet:
            res->value.val_VarLet = _copy_VarLet(nodeset->value.val_VarLet, imap);
            break;
        case NS_Stmt_While:
            res->value.val_While = _copy_While(nodeset->value.val_While, imap);
            break;
    }
    return res;
}

struct Stmt *copy_Stmt(struct Stmt *nodeset){
    if (nodeset == NULL) return NULL; // Cannot copy nothing.
    imap_t *imap = imap_init(64);
    struct Stmt * res = _copy_Stmt(nodeset, imap);
    imap_free(imap);
    return res;
}

