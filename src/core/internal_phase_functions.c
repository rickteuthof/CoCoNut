#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "core/error.h"
#include "core/internal_phase_functions.h"
#include "lib/array.h"
#include "lib/memory.h"



static phase_driver_t phase_driver;


void _exit_on_action_error() {
    if (phase_driver.action_error) {
        exit(1);
    }
}

void _reset_cycle() {
    phase_frame_t *frame = array_last(phase_driver.phase_stack);
    assert(frame != NULL);
    frame->cycle_notified = false;
}

bool _is_cycle_notified() {
    phase_frame_t *frame = array_last(phase_driver.phase_stack);
    assert(frame != NULL);
    return frame->cycle_notified;
}

phase_driver_t *_get_phase_driver() {
    return &phase_driver;
}

phase_frame_t *_top_frame() {
    return array_last(phase_driver.phase_stack);
}

void _push_frame() {
    phase_frame_t *frame = mem_alloc(sizeof(phase_frame_t));
    frame->cycle_notified = false;
    frame->curr_mark = NULL;
    frame->marks = NULL;
    array_append(phase_driver.phase_stack, frame);
}

void _pop_frame() {
    phase_frame_t *frame = array_pop(phase_driver.phase_stack);
    mem_free(frame);
}

void _initialize_phase_driver() {
    phase_driver.action_error = false, phase_driver.non_fatal_error = false,
    phase_driver.phase_stack = create_array();
    phase_driver.curr_sub_root = NULL;
}

cycle_mark_t *_ccn_new_mark(void *item) {
    cycle_mark_t *mark = mem_alloc(sizeof(cycle_mark_t));
    mark->notified = true;
    mark->node = item;
    return mark;
}

void _ccn_set_curr_mark(cycle_mark_t *mark) {
    assert(mark != NULL);
    phase_frame_t *frame = _top_frame();
    frame->curr_mark = mark;
}

void _ccn_start_phase(char *id) {
    printf("Starting phase: %s\n", id);
    _push_frame();
}

void _ccn_end_phase(char *id) {
    printf("Ending phase:   %s\n", id);
    _pop_frame();
}