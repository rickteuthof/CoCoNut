#include <stdbool.h>
#include <stdio.h>

#include "ast.h"
#include "filegen-driver.h"
#include "memory.h"

#define out(...) fprintf(fp, __VA_ARGS__)

static void generate_node(struct Node *node, FILE *fp, bool header) {
    out("struct %s *copy_%s(struct %s *node)", node->id, node->id, node->id);

    if (header) {
        out(";\n\n");
    } else {
        out(" {\n");

        out("    struct %s *res = mem_alloc(sizeof(struct %s));\n", node->id,
            node->id);

        for (int i = 0; i < array_size(node->children); i++) {
            struct Child *c = array_get(node->children, i);
            out("    res->%s = copy_%s(node->%s);\n", c->id, c->type, c->id);
        }

        for (int i = 0; i < array_size(node->attrs); i++) {
            struct Attr *attr = array_get(node->attrs, i);
            if (attr->type == AT_string) {
                out("    res->%s = strdup(node->%s);\n", attr->id, attr->id);
            } else {
                out("    res->%s = node->%s;\n", attr->id, attr->id);
            }
        }
        out("    return res;\n");
        out("}\n\n");
    }
}

static void generate_nodeset(struct Nodeset *nodeset, FILE *fp, bool header) {

    out("struct %s *copy_%s(struct %s *nodeset)", nodeset->id, nodeset->id,
        nodeset->id);

    if (header) {

        out(";\n\n");
    } else {
        out(" {\n");
        out("    struct %s *res = mem_alloc(sizeof(struct %s));\n",
            nodeset->id, nodeset->id);

        out("    res->type = nodeset->type;\n");
        out("    switch (nodeset->type) {\n");
        for (int i = 0; i < array_size(nodeset->nodes); i++) {
            char *node = array_get(nodeset->nodes, i);
            out("    case NS_%s_%s:\n", nodeset->id, node);
            out("        res->value.val_%s = "
                "copy_%s(nodeset->value.val_%s);\n",
                node, node, node);
            out("        break;\n");
        }
        out("    }\n");
        out("    return res;\n");
        out("}\n\n");
    }
}

static void generate(struct Config *c, FILE *fp, bool header) {
    if (header)
        out("#pragma once\n");

    out("#include \"ast.h\"\n");
    out("#include \"create-ast.h\"\n");
    if (!header)
        out("#include \"memory.h\"\n");
    out("#include \"copy-ast.h\"\n");
    out("#include <string.h>\n");

    out("\n");

    out("// Node create functions\n");
    for (int i = 0; i < array_size(c->nodes); i++) {
        generate_node(array_get(c->nodes, i), fp, header);
    }

    out("// Nodeset create functions\n");
    for (int i = 0; i < array_size(c->nodesets); i++) {
        generate_nodeset(array_get(c->nodesets, i), fp, header);
    }
}

void generate_copy_definitions(struct Config *c, FILE *fp) {
    generate(c, fp, false);
}

void generate_copy_header(struct Config *c, FILE *fp) {
    generate(c, fp, true);
}