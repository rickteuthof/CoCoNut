#pragma once

#include "cocogen/ast.h"
#include <stdio.h>

void generate_reporting_definitions(Config *c, FILE *fp);

void generate_reporting_headers(Config *c, FILE *fp);

void generate_reporting_traversal(Config *c, FILE *fp);
