// Hash: 1fabc23d00d09394712ebc11a0e33a24
#pragma once
#include "lib/imap.h"

struct VarLet;
struct VarLet *_copy_VarLet(struct VarLet *node, imap_t *imap);
struct VarLet *copy_VarLet(struct VarLet *node);
