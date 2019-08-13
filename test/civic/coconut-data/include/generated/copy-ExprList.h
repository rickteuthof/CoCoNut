// Hash: 0624d4152c0617b22ca17c7560e5b107
#pragma once
#include "lib/imap.h"

struct ExprList;
struct ExprList *_copy_ExprList(struct ExprList *node, imap_t *imap);
struct ExprList *copy_ExprList(struct ExprList *node);
