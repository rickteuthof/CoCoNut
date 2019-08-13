// Hash: 16b156e3bb9be8cca59ddae782f6cffa
#pragma once
#include "lib/imap.h"

struct Ternary;
struct Ternary *_copy_Ternary(struct Ternary *node, imap_t *imap);
struct Ternary *copy_Ternary(struct Ternary *node);
