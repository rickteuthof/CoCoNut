#include <assert.h>
#include <string.h>

#include "lib/memory.h"
#include "lib/str.h"
#include "cocogen/ast.h"
#include "cocogen/create-ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/gen-subtree-functions.h"

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


static inline void generate_action_traversal(Traversal *trav, FILE *fp, char *root, bool is_top_root) {
    out("trav_start_%s(root, TRAV_%s);\n", root, trav->id);
}

static inline void generate_action_phase(Phase *phase, FILE *fp, char *root, bool is_top_root) {
    if (!is_top_root) {
        out("%s_%s(root);\n", phase->id, root);
    } else {
        out("%s(root);\n", phase->id);
    }
}

static inline void generate_action_pass(Pass *pass, FILE *fp, char *root, bool is_top_root) {
    if (pass->func != NULL) {
        out("root = %s(root);\n", pass->func);
    } else {
        out("pass_%s_entry(root);\n", pass->id);
    }
}

static void generate_action(Action *action, FILE *fp, char *root, bool is_top_root) {
    switch (action->type) {
    case ACTION_TRAVERSAL:
        generate_action_traversal(action->action, fp, root, is_top_root);
        break;
    case ACTION_PHASE:
        generate_action_phase(action->action, fp, root, is_top_root);
        break;
    case ACTION_PASS:
        generate_action_pass(action->action, fp, root, is_top_root);
        break;
    default:
        break;
    }
}

void generate_phase_body(Phase *phase, FILE *fp, char *root, bool is_top_root) {
    if (is_top_root) {
        out("void %s(%s *temp_root) {\n", phase->id, root);
    } else {
        out("void %s_%s(%s *temp_root) {\n", phase->id, root, root);
    }
    generate_start_phase(phase, fp);

    if (phase->root != NULL && is_top_root) {
        out("%s *root = temp_root;\n", phase->root);
        subtree_generate_call_find_sub_root(root, phase->root, fp);
    } else {
        out("%s *root = temp_root;\n", root);
    }

    if (phase->cycle) {
        out("do {\n");
        out("_reset_cycle();\n");
    }
    char *new_root = phase->root == NULL ? root : phase->root;
    bool new_is_top_root = phase->root == NULL ? is_top_root : false;

    for (int i = 0; i < array_size(phase->actions); i++) {
        Action *action = array_get(phase->actions, i);
        generate_action(action, fp, new_root, new_is_top_root);
        out("_exit_on_action_error();\n");
    }

    if (phase->cycle) {
        out("} while (_is_cycle_notified()); \n");
    }

    generate_end_phase(phase, fp);
    out("}\n\n");
}


static inline void generate_include_pass(Action *action, FILE *fp) {
    Pass *pass = action->action;
    out("#include \"generated/pass-%s.h\"\n", pass->id);
}

static inline void generate_include_traversal(Action *action, FILE *fp) {
    Traversal *trav = action->action;
    out("#include \"generated/traversal-%s.h\"\n", trav->id);
}

static inline void  generate_include_phase(Action *action, FILE *fp) {
    Phase *phase = action->action;
    out("#include \"generated/phase-%s.h\"\n", phase->id);
}

static void generate_include_action_header(Action *action, FILE *fp) {
    switch (action->type) {
    case ACTION_TRAVERSAL:
        generate_include_traversal(action, fp);
        break;
    case ACTION_PHASE:
        generate_include_phase(action, fp);
        break;
    case ACTION_PASS:
        generate_include_pass(action, fp);
        break;
    default:
        break;
    }
}

void generate_phase_function_definitions(Config *config, FILE *fp,
                                         Phase *phase) {

    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include \"generated/phase-%s.h\"\n", phase->id);
    out("#include <stddef.h>\n");
    out("#include <stdio.h>\n");
    generate_include("generated/ast.h", fp);
    generate_include("generated/trav-ast.h", fp);
    generate_include("generated/internal/_sub_root_handlers.h", fp);

    for (int i = 0; i < array_size(phase->actions); ++i) {
        generate_include_action_header(array_get(phase->actions, i), fp);
    }

    generate_phase_body(phase, fp, config->root_node->id, true);
}


void generate_phase_function_declarations(Config *config, FILE *fp,
                                          Phase *phase) {

    generate_include("generated/ast.h", fp);
    out("void %s(Root *root);\n", phase->id);
}


