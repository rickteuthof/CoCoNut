// Hash: 335492ed82f8520c39ccbce6a5739af7
#pragma once
#include "lib/imap.h"

struct LocalFunDef;
struct LocalFunDef *_copy_LocalFunDef(struct LocalFunDef *node, imap_t *imap);
struct LocalFunDef *copy_LocalFunDef(struct LocalFunDef *node);
