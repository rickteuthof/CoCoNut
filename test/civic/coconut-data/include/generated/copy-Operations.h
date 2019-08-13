// Hash: 1604aaf06d8e16acccd979c8275f8e32
#pragma once
#include "lib/imap.h"

struct Operations;
struct Operations *_copy_Operations(struct Operations *nodeset, imap_t *imap);
struct Operations *copy_Operations(struct Operations *nodeset);
