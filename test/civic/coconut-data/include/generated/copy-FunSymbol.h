// Hash: c25846fd3a15b982bb7497256c83a575
#pragma once
#include "lib/imap.h"

struct FunSymbol;
struct FunSymbol *_copy_FunSymbol(struct FunSymbol *node, imap_t *imap);
struct FunSymbol *copy_FunSymbol(struct FunSymbol *node);
