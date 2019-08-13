// Hash: af28c29a686569d7ebb3c15611b384d2
// Do not include "lib/imap.h", header does it for us.
#include "lib/memory.h"
#include "generated/copy-StmtList.h"
#include "generated/ast-StmtList.h"

struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *, imap_t *);
struct Stmt;
struct Stmt *_copy_Stmt(struct Stmt *, imap_t *);
struct StmtList *_copy_StmtList(struct StmtList *node, imap_t *imap) {
    if (node == NULL) return NULL;
    struct StmtList *res = mem_alloc(sizeof(struct StmtList));
    imap_insert(imap, node, res);
    res->next = _copy_StmtList(node->next, imap);
    res->stmt = _copy_Stmt(node->stmt, imap);
    return res;
}

struct StmtList *copy_StmtList(struct StmtList *node) {
    if (node == NULL) return NULL; // Cannot copy nothing.

    imap_t *imap = imap_init(64);
    struct StmtList * res = _copy_StmtList(node, imap);
    imap_free(imap);
    return res;
}

