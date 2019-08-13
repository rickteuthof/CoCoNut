// Hash: 782f9b0b6daa7e2b74e6825788ce728f
#pragma once
#include "lib/imap.h"

struct FunctionParts;
struct FunctionParts *_copy_FunctionParts(struct FunctionParts *nodeset, imap_t *imap);
struct FunctionParts *copy_FunctionParts(struct FunctionParts *nodeset);
