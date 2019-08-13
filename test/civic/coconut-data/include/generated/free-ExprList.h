// Hash: 0624d4152c0617b22ca17c7560e5b107
#pragma once
#include <stdbool.h>
#include <string.h>
#include "lib/memory.h"
#include "generated/ast.h"
void free_ExprList_tree(struct ExprList* node);void free_ExprList_node(struct ExprList* node);
