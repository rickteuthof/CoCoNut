#pragma once

#include "lib/set.h"
#include "cocogen/ast.h"

void subtree_generate_set_handler(char *root, ccn_set_t *funcs);
void subtree_generate_find_traversal_body(char *trav_name, char *target);
void subtree_generate_phase_functions(array *phases);
void subtree_generate_traversals(Config *config);
void subtree_generate_call_find_sub_root(char *root, char *to_find, FILE *fp, Phase *phase);