// Hash: 2a17d582c98658539abe0f791e2036ae
#pragma once
#include "lib/imap.h"

struct Symbol;
struct Symbol *_copy_Symbol(struct Symbol *node, imap_t *imap);
struct Symbol *copy_Symbol(struct Symbol *node);
