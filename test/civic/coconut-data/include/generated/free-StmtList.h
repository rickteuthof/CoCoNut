// Hash: af28c29a686569d7ebb3c15611b384d2
#pragma once
#include <stdbool.h>
#include <string.h>
#include "lib/memory.h"
#include "generated/ast.h"
void free_StmtList_tree(struct StmtList* node);void free_StmtList_node(struct StmtList* node);
