#pragma once

/**
 * This module contains all the functions that are needed for the phase driver.
 * These functions will be used in the real user compiler by the phase driver.
 * So not in the metacompiler.
 * The user however should never need these functions thats why they are
 * prefixed with an underscore.
 */

#include <stdbool.h>

#include "lib/array.h"
#include "generated/enum.h"

typedef struct CCNsubroot sub_root_t;

// If not disallowed then mandatory.
typedef struct lifetime_executer {
    bool disallowed;
    void (*func)(void *, bool, array*);
    array *data;

} lifetime_executer_t;

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
} phase_frame_t;

typedef struct phase_driver {
    bool action_error;
    bool non_fatal_error;
    array *phase_stack;
    array *passes_time_frames;
    array *cycles_time_frames;
    sub_root_t *curr_sub_root;
} phase_driver_t;

phase_frame_t *_top_frame();
cycle_mark_t *_ccn_new_mark(void *);
bool _ccn_mark_apply(void *);
bool _ccn_mark_remove(void *);
void _ccn_start_phase(char *id);
void _ccn_end_phase(char *id);
void _exit_on_action_error();
bool _is_cycle_notified();
void _reset_cycle();
void _initialize_phase_driver();
void _ccn_set_curr_mark(cycle_mark_t *mark);
void _ccn_new_passes_time_frame(char *id, double time);
void _ccn_new_cycle_time_frame(char *id, double time);
void _print_top_n_time(int n);

phase_driver_t *_get_phase_driver();