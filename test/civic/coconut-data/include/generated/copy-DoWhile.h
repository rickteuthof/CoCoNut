// Hash: 6d90e000f1cba5ba3b8016ed76d1b8fe
#pragma once
#include "lib/imap.h"

struct DoWhile;
struct DoWhile *_copy_DoWhile(struct DoWhile *node, imap_t *imap);
struct DoWhile *copy_DoWhile(struct DoWhile *node);
