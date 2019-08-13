// Hash: df86d0e15495f375db62ae5bf23c0be7
#pragma once
#include "lib/imap.h"

struct While;
struct While *_copy_While(struct While *node, imap_t *imap);
struct While *copy_While(struct While *node);
