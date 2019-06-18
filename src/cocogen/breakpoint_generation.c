
#include "cocogen/breakpoint_generation.h"

void generate_breakpoint(Config *c, FILE *fp) {
    out("#pragma once\n\n");
    size_t size = 0;
    int indent = 0;
    out("enum ACTION_IDS {\n");
    indent++;
    array *traversals = c->traversals;
    for (int i = 0; i < array_size(traversals); ++i) {
        Traversal *trav = array_get(traversals, i);
        out_enum_field("ACTION_ID_%s", trav->id);
        size++;
    }

    array *passes = c->passes;
    for (int i = 0; i < array_size(passes); ++i) {
        Pass *pass = array_get(passes, i);
        out_enum_field("ACTION_ID_%s", pass->id);
        size++;
    }

    array *phases = c->phases;
    for (int i = 0; i < array_size(phases); ++i) {
        Phase *phase = array_get(phases, i);
        if (phase->original_ref == NULL) {
            out_enum_field("ACTION_ID_%s", phase->id);
            size++;
        }
    }

    out("    ACTION_ID_NULL\n};\n");
    indent--;
    out_start_func("inline int get_number_of_actions()");
    out_statement("return %d", size);
    out_end_func();

    out("smap_t *create_enum_mapping();\n\n");
}


static void generate_phase(Config *c, FILE *fp) {
    int indent = 0;
    out("int get_number_of_actions();\n");
    out_start_func("smap_t *create_enum_mapping()");
    out_statement("smap_t *map = smap_init(get_number_of_actions())");
    out_statement("enum ACTION_IDS *action_id = NULL");
    size_t size = 0;

    array *traversals = c->traversals;
    for (int i = 0; i < array_size(traversals); ++i) {
        Traversal *trav = array_get(traversals, i);
        out_statement("action_id = mem_alloc(sizeof(enum ACTION_IDS))");
        out_statement("*action_id = ACTION_ID_%s", trav->id);
        out_statement("smap_insert(map, \"%s\", action_id)", trav->id);
        size++;
    }

    array *passes = c->passes;
    for (int i = 0; i < array_size(passes); ++i) {
        Pass *pass = array_get(passes, i);
        out_statement("action_id = mem_alloc(sizeof(enum ACTION_IDS))");
        out_statement("*action_id = ACTION_ID_%s", pass->id);
        out_statement("smap_insert(map, \"%s\", action_id)", pass->id);
        size++;
    }

    array *phases = c->phases;
    for (int i = 0; i < array_size(phases); ++i) {
        Phase *phase = array_get(phases, i);
        if (phase->original_ref == NULL) {
            out_statement("action_id = mem_alloc(sizeof(enum ACTION_IDS))");
            out_statement("*action_id = ACTION_ID_%s", phase->id);
            out_statement("smap_insert(map, \"%s\", action_id)", phase->id);

            size++;
        }
    }
    out_statement("return map");
    out_end_func();
}

void generate_breakpoint_body(Config *c, FILE *fp) {
    Phase *phase = c->start_phase;
    out("#include \"lib/array.h\"\n");
    out("#include \"lib/str.h\"\n");
    out("#include \"lib/smap.h\"\n");
    out("#include \"generated/breakpoint-finder.h\"\n");
    generate_phase(c, fp);

    out("\n");
}