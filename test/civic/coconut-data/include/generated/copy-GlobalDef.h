// Hash: 47bbee1cc9f9bf097e4833f85bb45167
#pragma once
#include "lib/imap.h"

struct GlobalDef;
struct GlobalDef *_copy_GlobalDef(struct GlobalDef *node, imap_t *imap);
struct GlobalDef *copy_GlobalDef(struct GlobalDef *node);
