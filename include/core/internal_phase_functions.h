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

typedef struct phase_frame {
    bool cycle_notified;
} phase_frame_t;

typedef struct phase_driver {
    bool action_error;
    bool non_fatal_error;
    array *phase_stack;
    sub_root_t *curr_sub_root;
} phase_driver_t;

phase_frame_t *_top_frame();
void _ccn_start_phase(char *id);
void _ccn_end_phase(char *id);
void _exit_on_action_error();
bool _is_cycle_notified();
void _reset_cycle();
void _initialize_phase_driver();

phase_driver_t *_get_phase_driver();