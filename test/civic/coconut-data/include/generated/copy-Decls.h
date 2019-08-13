// Hash: da1486863569ad210a4555708de59ea2
#pragma once
#include "lib/imap.h"

struct Decls;
struct Decls *_copy_Decls(struct Decls *node, imap_t *imap);
struct Decls *copy_Decls(struct Decls *node);
