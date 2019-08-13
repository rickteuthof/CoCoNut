// Hash: 514d9d5eed2b7d56245866708d0e1d89
#pragma once
#include "lib/imap.h"

struct BinOp;
struct BinOp *_copy_BinOp(struct BinOp *node, imap_t *imap);
struct BinOp *copy_BinOp(struct BinOp *node);
