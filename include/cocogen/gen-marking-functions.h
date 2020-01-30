#pragma once

#include "cocogen/ast.h"
#include <stdio.h>

void generate_marking_definitions(Config *c, FILE *fp);

void generate_marking_headers(Config *c, FILE *fp);

void generate_marking_traversal(Config *c, FILE *fp);
