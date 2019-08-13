// Hash: 1e4fc8c57864026894e956f2ce63ce36
#pragma once
#include "lib/imap.h"

struct FunDef;
struct FunDef *_copy_FunDef(struct FunDef *node, imap_t *imap);
struct FunDef *copy_FunDef(struct FunDef *node);
