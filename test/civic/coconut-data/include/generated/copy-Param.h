// Hash: 31ba4afd09094183d749087a75279dea
#pragma once
#include "lib/imap.h"

struct Param;
struct Param *_copy_Param(struct Param *node, imap_t *imap);
struct Param *copy_Param(struct Param *node);
