#pragma once

#include "cocogen/ast.h"
#include "cocogen/config.h"
#include <stdio.h>

#define out(...) fprintf(fp, __VA_ARGS__)
#define out_struct(...) print_indent_level(indent, fp); indent++; fprintf(fp, "struct "); fprintf(fp, __VA_ARGS__); fprintf(fp, " {\n")
#define out_field(...) print_indent_level(indent, fp); fprintf(fp, __VA_ARGS__); fprintf(fp, ";\n")
#define out_struct_end() indent--; print_indent_level(indent, fp); fprintf(fp, "};\n\n")
#define out_statement(...) print_indent_level(indent, fp); fprintf(fp, __VA_ARGS__); fprintf(fp, ";\n")
#define out_start_func(...) print_indent_level(indent, fp); indent++; fprintf(fp, __VA_ARGS__); fprintf(fp, " {\n")
#define out_end_func() indent--; print_indent_level(indent, fp); fprintf(fp, "}\n\n")
#define out_begin_if(...) print_indent_level(indent, fp); indent++; fprintf(fp, "if ("); fprintf(fp, __VA_ARGS__); fprintf(fp, ") {\n")
#define out_end_if() indent--; print_indent_level(indent, fp); fprintf(fp, "}\n\n");

void print_indent_level(int indent_level, FILE *);
void generate_node_header_includes(Config *, FILE *, Node *);
