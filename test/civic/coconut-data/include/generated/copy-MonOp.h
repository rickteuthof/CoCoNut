// Hash: b0bfe9d720169c1396aafc91b36ae925
#pragma once
#include "lib/imap.h"

struct MonOp;
struct MonOp *_copy_MonOp(struct MonOp *node, imap_t *imap);
struct MonOp *copy_MonOp(struct MonOp *node);
