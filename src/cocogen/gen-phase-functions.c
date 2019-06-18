#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "lib/memory.h"
#include "lib/str.h"
#include "cocogen/ast.h"
#include "cocogen/create-ast.h"
#include "cocogen/filegen-driver.h"
#include "cocogen/filegen-util.h"
#include "cocogen/gen-subtree-functions.h"
#include "cocogen/command_opts.h"

static inline void generate_start_phase(Phase *phase, FILE *fp, int indent) {
    assert(phase != NULL);
    out_statement("_ccn_start_phase(\"%s\")", phase->id);
}

static inline void generate_end_phase(Phase *phase, FILE *fp, int indent) {
    assert(phase != NULL);
    out_statement("_ccn_end_phase(\"%s\")", phase->id);
}

static inline void generate_include(char *filename, FILE *fp) {
    out("#include \"%s\"\n", filename);
}


static inline void generate_action_traversal(Traversal *trav, FILE *fp, char *root, bool is_top_root, int *_indent) {
    int indent = *_indent;
    out_statement("trav_start_%s(root, TRAV_%s)", root, trav->id);
}

static inline void generate_action_phase(Phase *phase, FILE *fp, char *root, bool is_top_root, int *_indent) {
    int indent = *_indent;
    if (!is_top_root) {
        out_statement("%s_%s(root)", phase->id, root);
    } else {
        out_statement("%s(root)", phase->id);
    }
}

static inline void generate_action_pass(Pass *pass, FILE *fp, char *root, bool is_top_root, int *_indent) {
    int indent = *_indent;
    if (pass->func != NULL) {
        out_statement("root = %s(root)", pass->func);
    } else {
        out_statement("pass_%s_entry(root)", pass->id);
    }
}

static void generate_action(Action *action, FILE *fp, char *root, bool is_top_root, int *_indent) {
    switch (action->type) {
    case ACTION_TRAVERSAL:
        generate_action_traversal(action->action, fp, root, is_top_root, _indent);
        break;
    case ACTION_PHASE:
        generate_action_phase(action->action, fp, root, is_top_root, _indent);
        break;
    case ACTION_PASS:
        generate_action_pass(action->action, fp, root, is_top_root, _indent);
        break;
    default:
        break;
    }
}

static char *get_action_id(Action *action) {
    switch (action->type) {
    case ACTION_TRAVERSAL:
        return ((Traversal *)action->action)->id;
    case ACTION_PASS:
        return ((Pass *)action->action)->id;
    case ACTION_PHASE:
        return ((Phase *)action->action)->id;
    case ACTION_REFERENCE:
        return (char *)action;
    default:
        return NULL;
    }
}

void generate_lifetimes(array *lifetimes, FILE *fp, bool inclusive_start, bool inclusive_end) {
    if (lifetimes == NULL)
        return;
    for (int i = 0; i < array_size(lifetimes); ++i) {
        Range_spec_t *spec = array_get(lifetimes, i);
        if (spec->push && spec->inclusive == inclusive_start) {
            if (spec->values != NULL) {
                for (int j = 0; j < array_size(spec->values); ++j) {
                    char *val = array_get(spec->values, j);
                    out("_push_chk_frame(\"%s%s\", %s);\n", spec->consistency_key, val, spec->type);
                }
            } else {
                out("_push_chk_frame(\"%s\", %s);\n", spec->consistency_key, spec->type);
            }
        } else if (!spec->push && spec->inclusive == inclusive_end) {
            out("_pop_chk_frame(\"%s\");\n", spec->consistency_key);
        }
    }
}

// TODO: handle CHK traversal for sub_roots.
void generate_action_list(array *actions, FILE *fp, char *new_root, bool is_top_root, int *_indent) {
    int indent = *_indent;
     for (int i = 0; i < array_size(actions); ++i){
        Action *action = array_get(actions, i);
        //generate_lifetimes(action->range_specs, fp, true, false);
        out_statement("pd->action_id++");
        out_statement("pd->current_action = \"%s\"", action->id);
        out_statement("trav_start_%s(root, TRAV__CCN_CHK)", new_root);

        if (global_options.profiling) {
            out_statement("start = clock()");
        }

        generate_action(action, fp, new_root, is_top_root, &indent);
        out_statement("_ccn_check_points(ACTION_ID_%s, \"%s\")", action->id, action->id);
        if (global_options.profiling) {
            out_statement("end = clock()");
        }
        //generate_lifetimes(action->range_specs, fp, false, true);

        if (global_options.profiling) {
            if (action->type != ACTION_PHASE) {
                char *id = get_action_id(action);
                if (id == NULL)
                    break;
                out_statement("_ccn_new_passes_time_frame(\"%s\", (end-start)/CLOCKS_PER_SEC)", id); // TODO handle error in time frame.(clock() can return -1 and so on).
            } else {
                Phase *phase = action->action;
                if (phase->cycle) {
                    out_statement("_ccn_new_cycle_time_frame(\"%s\", (end-start)/CLOCKS_PER_SEC)", phase->id); // TODO handle error in time frame.
                }
            }
        }
        out_statement("_exit_on_action_error()");
    }
    *_indent = indent;
}

void generate_phase_body(Phase *phase, FILE *fp, char *root, bool is_top_root) {
    char *new_root = phase->root == NULL ? root : phase->root;
    bool new_is_top_root = phase->root == NULL ? is_top_root : false;
    int indent = 0;

    if (is_top_root) {
        out_start_func("void %s(%s *temp_root)", phase->id, root);
    } else {
        out_start_func("void %s_%s(%s *temp_root)", phase->id, root, root);
    }
    out_statement("phase_driver_t *pd = _get_phase_driver()");
    out_statement("pd = pd");
    out_statement("const int action_id = pd->action_id");
    if (global_options.profiling) {
        out_statement("double start");
        out_statement("double end");
    }
    generate_start_phase(phase, fp, indent);
    out_statement("phase_frame_t *curr_frame = _top_frame()");
    if (phase->root != NULL) {
        out_statement("curr_frame->curr_root = NT_%s", phase->root);
        out_statement("%s *root = NULL", phase->root);
        subtree_generate_call_find_sub_root(root, phase->root, fp, phase, &indent);

    } else {
        out_statement("curr_frame->curr_root = NT_%s", root);
        out_statement("%s *root = temp_root", root);
    }

    if (phase->cycle && phase->root != NULL) {
        out_statement("bool all_notified = false");
        out_statement("array *marks = array_init(10)");
        out_statement("curr_frame->marks = marks");
        out_statement("%s *temp = root", phase->root);
        out_begin_while("temp != NULL");
        out_statement("array_append(marks, _ccn_new_mark(temp))");
        out_statement("temp = temp->next");
        out_end_while();
        out_statement("cycle_mark_t *mark = NULL");
        out_begin_while("!all_notified");
        out_statement("_reset_cycle()");
        out_statement("all_notified = true");
        out_begin_for("int i = 0; i < array_size(marks); ++i");
        out_statement("pd->action_id = action_id");
        out_statement("mark = array_get(marks, i)");
        out_begin_if("!mark->notified");
        out_statement("continue");
        out_end_if();
        out_statement("mark->notified = false");
        out_statement("_ccn_set_curr_mark(mark)");
        out_statement("all_notified = false");
        out_statement("%s *root = mark->node", new_root);
        out_statement("%s *next = root->next", new_root);
        out_statement("root->next = NULL");
        generate_action_list(phase->actions, fp, new_root, new_is_top_root, &indent);
        out_statement("root->next = next");
        out_statement("_ccn_check_points(ACTION_ID_%s, \"%s\")", phase->id, phase->id);
        out_end_for();
        out_end_while();
    } else if (phase->cycle && phase->root == NULL) {
        out("do {\n");
        indent++;
        out_statement("_reset_cycle()");
        out_statement("pd->action_id = action_id");
        generate_action_list(phase->actions, fp, new_root, new_is_top_root, &indent);
        out_statement("_ccn_check_points(ACTION_ID_%s, \"%s\")", phase->id, phase->id);
        indent--;
        out_statement("} while(_is_cycle_notified())");
        out("\n");
    } else {
        generate_action_list(phase->actions, fp, new_root, new_is_top_root, &indent);
    }

    out_statement("_ccn_check_points(ACTION_ID_%s, \"%s\")", phase->id, phase->id);
    generate_end_phase(phase, fp, indent);
    out_end_func();
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
    out("#include <stdint.h>\n");
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

void print_action_ids(array *phases) {
    for (int j = 0; j < array_size(phases); ++j) {
        Phase *phase = array_get(phases, j);
    for (int i = 0; i <array_size(phase->actions); ++i) {
        Action *action = array_get(phase->actions, i);
        printf("ACTION, ID: %s, %lu\n", action->id, (unsigned long)action->id_counter);
    }
    }
}



void generate_phase_function_definitions(Config *config, FILE *fp,
                                         Phase *phase) {

    out("#include \"core/internal_phase_functions.h\"\n");
    out("#include \"generated/phase-%s.h\"\n", phase->id);
    out("#include <stddef.h>\n");
    out("#include <stdio.h>\n");
    out("#include <time.h>\n");
    generate_include("generated/ast.h", fp);
    generate_include("generated/trav-ast.h", fp);
    generate_include("generated/internal/_sub_root_handlers.h", fp);
    generate_include("generated/breakpoint-finder.h", fp);

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


