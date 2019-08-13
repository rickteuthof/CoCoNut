// Hash: bb6639b82c8f18c2af9886944317b845
#pragma once
#include "lib/imap.h"

struct Stmt;
struct Stmt *_copy_Stmt(struct Stmt *nodeset, imap_t *imap);
struct Stmt *copy_Stmt(struct Stmt *nodeset);
