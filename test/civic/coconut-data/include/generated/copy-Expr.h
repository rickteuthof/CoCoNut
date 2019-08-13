// Hash: 6d316f510e6ccaf4826835131137a57e
#pragma once
#include "lib/imap.h"

struct Expr;
struct Expr *_copy_Expr(struct Expr *nodeset, imap_t *imap);
struct Expr *copy_Expr(struct Expr *nodeset);
