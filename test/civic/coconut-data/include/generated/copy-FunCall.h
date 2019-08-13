// Hash: cc2abd438fff2facf1c543ad95507122
#pragma once
#include "lib/imap.h"

struct FunCall;
struct FunCall *_copy_FunCall(struct FunCall *node, imap_t *imap);
struct FunCall *copy_FunCall(struct FunCall *node);
