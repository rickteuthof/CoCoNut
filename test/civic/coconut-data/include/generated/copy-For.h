// Hash: 1b5e131a901dfeb50ab1b084b4472381
#pragma once
#include "lib/imap.h"

struct For;
struct For *_copy_For(struct For *node, imap_t *imap);
struct For *copy_For(struct For *node);
