#pragma once

/**
 * This module contains all the functions that are needed for the phase driver.
 * These functions will be used in the real user compiler by the phase driver.
 * So not in the metacompiler.
 * The user however should never need these functions thats why they are
 * prefixed with an underscore.
 */

#include <stdbool.h>
#include <stdint.h>

#include "lib/array.h"
#include "lib/smap.h"
#include "generated/enum.h"
#include "generated/breakpoint-finder.h"

typedef struct CCNsubroot sub_root_t;

enum ccn_chk_types {
    CCN_CHK_DISALLOWED,
    CCN_CHK_MANDATORY,
};

typedef struct ccn_chk_frame {
    enum ccn_chk_types type;
    array *values;
    int ref_counter;
} ccn_chk_frame_t;

typedef struct time_frame {
    char *id;
    char *parent_phase;
    double time_sec;
} time_frame_t;

typedef struct cycle_mark {
    bool notified;
    void *node;
} cycle_mark_t;

typedef struct phase_frame {
    char *phase_id;
    bool cycle_notified;
    array *marks;
    NodeType curr_root;
    cycle_mark_t *curr_mark;
    size_t cycles;
} phase_frame_t;

typedef struct point_frame {
    array *ids;
    enum ACTION_IDS current_id;
    size_t index;
    char *action;
    size_t cycle_counter;
} point_frame_t;

typedef struct phase_driver {
    bool initialized;
    bool action_error;
    bool non_fatal_error;
    array *phase_stack;
    array *passes_time_frames;
    array *cycles_time_frames;
    sub_root_t *curr_sub_root;
    smap_t *consistency_map;
    smap_t *id_to_enum_map;
    int level;
    uint32_t action_id;
    point_frame_t *breakpoint;
    array *inspection_points;
    char *current_action;
    void *ast;
} phase_driver_t;


phase_frame_t *_top_frame();
cycle_mark_t *_ccn_new_mark(void *);
bool _ccn_mark_apply(void *);
bool _ccn_mark_remove(void *);
void _ccn_start_phase(char *id);
void _ccn_end_phase(char *id);
void _push_chk_frame(char *key, enum ccn_chk_types type);
void _pop_chk_frame(char *key);
void _exit_on_action_error();
bool _is_cycle_notified();
void _reset_cycle();
void _initialize_phase_driver();
void _ccn_set_curr_mark(cycle_mark_t *mark);
void _ccn_new_passes_time_frame(char *id, double time);
void _ccn_new_cycle_time_frame(char *id, double time);
void _ccn_check_points(enum ACTION_IDS id, char *curr_action);
bool ccn_set_breakpoint(char *breakpoint);
bool ccn_set_inspect_point(char *inspect);
void _print_top_n_time(int n);
void _print_path();

phase_driver_t *_get_phase_driver();