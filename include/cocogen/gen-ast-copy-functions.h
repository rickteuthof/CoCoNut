#pragma once
#include <stdio.h>

#include "cocogen/ast.h"

void ast_generate_copy_node_header(Config *c, FILE *fp, Node *n);
void ast_generate_copy_node_definitions(Config *c, FILE *fp, Node *n);
void ast_generate_copy_nodeset_header(Config *c, FILE *fp, Nodeset *n);
void ast_generate_copy_nodeset_definitions(Config *c, FILE *fp, Nodeset *n);
void ast_generate_copy_header(Config *config, FILE *fp);
