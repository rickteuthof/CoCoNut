// Hash: 33e19f933fee95125167d08907d344d2
#pragma once
#include "lib/imap.h"

struct FunHeader;
struct FunHeader *_copy_FunHeader(struct FunHeader *node, imap_t *imap);
struct FunHeader *copy_FunHeader(struct FunHeader *node);
