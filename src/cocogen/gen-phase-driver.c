#include "cocogen/ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/str-ast.h"
#include "lib/memory.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "cocogen/command_opts.h"

// TODO: maybe allow to print to multiple files at once.
// We no go over the phases two or three times, which can be changed.

// TODO call right traversal function when a root node is specified.
// TODO handle passes when a certain root is specified, needs to accept that
// root.

static inline void print_indent(int level, char *single_indent, FILE *fp) {
    for (int i = 0; i < level; i++)
        out(single_indent);
}

static inline void generate_start_phase(Phase *phase, FILE *fp) {
    assert(phase != NULL);
    out("_ccn_start_phase(\"%s\");\n", phase->id);
}

static inline void generate_end_phase(Phase *phase, FILE *fp) {
    assert(phase != NULL);
    out("_ccn_end_phase(\"%s\");\n", phase->id);
}

static inline void generate_include(char *filename, FILE *fp) {
    out("#include \"%s\"\n", filename);
}


void generate_phase_driver_definitions(Config *config, FILE *fp) {
    array *phases = config->phases;
    Phase *root_phase = NULL;

    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include \"generated/ast.h\"\n");

    for (int i = 0; i < array_size(phases); ++i) {
        Phase *tmp = array_get(phases, i);
        if (tmp->start) {
            root_phase = tmp;
        }
    }

    out("#include \"generated/phase-%s.h\"\n", root_phase->id);
    out("#include <time.h>\n");

    out("void phasedriver_run(%s *root) {\n\t_initialize_phase_driver();", config->root_node->id);
    out("phase_driver_t *pd = _get_phase_driver();\n");
    out("pd->ast = root;\n");
    out("set_allocators();\n");
    out("double start = 0.0, end = 0.0;\n");
    out("start = clock();\n");
    out("%s(root);\n", root_phase->id);
    out("end = clock();\n");
    out("pd->total_time = (end - start)/CLOCKS_PER_SEC;\n");
    if (global_options.profiling) {
        out(" _print_top_n_time();\n");
    }
    out("phase_driver_destroy();\n");
    out("}\n");
}

void generate_phase_driver_header(Config *config, FILE *fp) {
    out("#pragma once\n");
    out("void phasedriver_run(Root *root);\n");
}
