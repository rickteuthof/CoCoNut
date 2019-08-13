// Hash: d370e4383f7aab78470bbb20eac500e8
#pragma once
#include "lib/imap.h"

struct GlobalDec;
struct GlobalDec *_copy_GlobalDec(struct GlobalDec *node, imap_t *imap);
struct GlobalDec *copy_GlobalDec(struct GlobalDec *node);
