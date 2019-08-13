// Hash: 4b5f0f88bdd5355115a58de9c899d7b4
#pragma once
#include "lib/imap.h"

struct Return;
struct Return *_copy_Return(struct Return *node, imap_t *imap);
struct Return *copy_Return(struct Return *node);
