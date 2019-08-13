// Hash: e88afa1e610a0d88acf5ce24ec97f504
#pragma once
#include "lib/imap.h"

struct IntConst;
struct IntConst *_copy_IntConst(struct IntConst *node, imap_t *imap);
struct IntConst *copy_IntConst(struct IntConst *node);
