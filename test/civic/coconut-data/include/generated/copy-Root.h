// Hash: 70eba40e9dab0c2491717f2637a08068
#pragma once
#include "lib/imap.h"

struct Root;
struct Root *_copy_Root(struct Root *node, imap_t *imap);
struct Root *copy_Root(struct Root *node);
