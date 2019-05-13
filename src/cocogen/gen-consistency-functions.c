#include <stdbool.h>
#include <stdio.h>

#include "cocogen/ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/str-ast.h"

#include "lib/set_implementations.h"
#include "lib/array.h"
#include "lib/memory.h"
#include "lib/smap.h"

void generate_headers(Config *c, FILE *fp) {
    ccn_set_t *generated = ccn_set_string_create(10);
    array *nodes = c->nodes;
    for (int i = 0; i < array_size(nodes); ++i) {
        Node *n = array_get(nodes, i);
        for (int j = 0; j < array_size(n->lifetimes); ++j) {
            Lifetime_t *lifetime = array_get(n->lifetimes, j);
            if (ccn_set_insert(generated, lifetime->start->func_to_target)) {
                out("void %s();\n", lifetime->start->func_to_target);
            }
            if (ccn_set_insert(generated, lifetime->end->func_to_target)) {
                out("void %s();\n", lifetime->end->func_to_target);
            }

        }
    }
}

void generate_consistency_definitions(Config *c, FILE *fp) {
}

void generate_consistency_headers(Config *c, FILE *fp) {
    generate_headers(c, fp);
}
