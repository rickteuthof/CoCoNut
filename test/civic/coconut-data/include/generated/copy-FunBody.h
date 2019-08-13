// Hash: b749bf704b901788bcd7cb60caea2822
#pragma once
#include "lib/imap.h"

struct FunBody;
struct FunBody *_copy_FunBody(struct FunBody *node, imap_t *imap);
struct FunBody *copy_FunBody(struct FunBody *node);
