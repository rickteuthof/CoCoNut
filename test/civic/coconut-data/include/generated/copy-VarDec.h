// Hash: 3e39a0cd59728ac5797ddd72e5100164
#pragma once
#include "lib/imap.h"

struct VarDec;
struct VarDec *_copy_VarDec(struct VarDec *node, imap_t *imap);
struct VarDec *copy_VarDec(struct VarDec *node);
