// Hash: af28c29a686569d7ebb3c15611b384d2
#pragma once
#include "lib/imap.h"

struct StmtList;
struct StmtList *_copy_StmtList(struct StmtList *node, imap_t *imap);
struct StmtList *copy_StmtList(struct StmtList *node);
