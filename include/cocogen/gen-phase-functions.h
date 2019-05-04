#pragma once

void generate_phase_function_definitions(Config *config, FILE *fp,
                                         Phase *phase);

void generate_phase_function_declarations(Config *config, FILE *fp,
                                          Phase *phase);

void generate_phase_sub_root_functions(array *phases);

void generate_sub_root_traversals(Config *config);