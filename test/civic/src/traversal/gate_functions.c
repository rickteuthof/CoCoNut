#include "generated/gate_functions.h"
#include "core/globals.h"

#include <stdbool.h>

bool LoadProgram_gate() {
    return true;
}

bool SemanticAnalysis_gate() {
    return true;
}

bool Gate_CodeGen() {
    return true;
}

bool Optimisations_gate() {
    return get_opt();
}