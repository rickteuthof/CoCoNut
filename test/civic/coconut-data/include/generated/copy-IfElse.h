// Hash: 49a6200318f4e38dbef3daba45e4ce7b
#pragma once
#include "lib/imap.h"

struct IfElse;
struct IfElse *_copy_IfElse(struct IfElse *node, imap_t *imap);
struct IfElse *copy_IfElse(struct IfElse *node);
