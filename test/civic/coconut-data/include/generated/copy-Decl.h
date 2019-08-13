// Hash: a1b06fb9abb037787acc985178482577
#pragma once
#include "lib/imap.h"

struct Decl;
struct Decl *_copy_Decl(struct Decl *nodeset, imap_t *imap);
struct Decl *copy_Decl(struct Decl *nodeset);
