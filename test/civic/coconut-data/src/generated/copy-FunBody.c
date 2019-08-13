// Hash: b749bf704b901788bcd7cb60caea2822
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-FunBody.h"
#include "generated/ast-FunBody.h"

struct LocalFunDef;
struct LocalFunDef *_copy_LocalFunDef(struct LocalFunDef *, imap_t *);
struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct VarDec;
struct VarDec *_copy_VarDec(struct VarDec *, imap_t *);
struct FunBody *_copy_FunBody(struct FunBody *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct FunBody *res = mem_alloc(sizeof(struct FunBody));
    imap_insert(imap, node, res);
    res->localfundef = _copy_LocalFunDef(node->localfundef, imap);
    res->stmtlist = _copy_StmtList(node->stmtlist, imap);
    res->vardec = _copy_VarDec(node->vardec, imap);
    return res;
}

struct FunBody *copy_FunBody(struct FunBody *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct FunBody * res = _copy_FunBody(node, imap);
    imap_free(imap);
    return res;
}

