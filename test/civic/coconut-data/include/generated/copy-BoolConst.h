// Hash: 657816c98ab8bae4509f890a4cf4b654
#pragma once
#include "lib/imap.h"

struct BoolConst;
struct BoolConst *_copy_BoolConst(struct BoolConst *node, imap_t *imap);
struct BoolConst *copy_BoolConst(struct BoolConst *node);
