// Hash: 121eeb949095a740dd78338f981bac61
#pragma once
#include "lib/imap.h"

struct Var;
struct Var *_copy_Var(struct Var *node, imap_t *imap);
struct Var *copy_Var(struct Var *node);
