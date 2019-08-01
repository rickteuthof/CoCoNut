#include "cocogen/gen-gate-functions.h"

void generate_gate_functions(Config *config, FILE *fp) {
    out("#include <stdbool.h>\n");
    int indent = 0;
    for (int i = 0; i < array_size(config->phases); ++i) {
        Phase *phase = array_get(config->phases, i);
        if (phase->gate_func != NULL) {
            out_statement("bool %s()", phase->gate_func);
        }
    }
}
