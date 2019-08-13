// Hash: e7edc9c998e6633c941feaada999a32e
#pragma once
#include "lib/imap.h"

struct Vars;
struct Vars *_copy_Vars(struct Vars *nodeset, imap_t *imap);
struct Vars *copy_Vars(struct Vars *nodeset);
