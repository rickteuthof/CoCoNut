#pragma once
#include "generated/enum.h"
#include "generated/traversal-ByteCode.h"
#include "generated/traversal-Context.h"
#include "generated/traversal-Print.h"
#include "generated/traversal-Refactor.h"
#include "generated/traversal-RenameFor.h"
#include "generated/traversal-SplitInit.h"
#include "generated/traversal-Symbols.h"
#include "generated/traversal-TypeCheck.h"
// Stack of traversals, so that new traversals can be started inside other traversals. 
NodeType node_replacement_type;
void *node_replacement;
void CCNtrav_push(TraversalType trav);
void CCNtrav_pop(void);
TraversalType trav_current(void);

