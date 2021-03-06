#pragma once

#include "cocogen/ast.h"
#include <stdio.h>

void generate_consistency_definitions(Config *c, FILE *fp);

void generate_consistency_headers(Config *c, FILE *fp);

void generate_check_traversal(Config *c, FILE *fp);
