// Hash: be4c521ad82189ec8e08be8055ccee09
#pragma once
#include "lib/imap.h"

struct Constants;
struct Constants *_copy_Constants(struct Constants *nodeset, imap_t *imap);
struct Constants *copy_Constants(struct Constants *nodeset);
