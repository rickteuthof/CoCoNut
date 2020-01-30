#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "cocogen/ast.h"
void ast_generate_free_header(Config *, FILE *);
void ast_generate_free_node_header(Config *c, FILE *fp, Node *n);
void ast_generate_free_node_definitions(Config *c, FILE *fp, Node *n);

void ast_generate_free_nodeset_header(Config *c, FILE *fp, Nodeset *n);
void ast_generate_free_nodeset_definitions(Config *c, FILE *fp, Nodeset *n);
