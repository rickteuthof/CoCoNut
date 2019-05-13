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

void _push_frame(char *id) {
    phase_frame_t *frame = mem_alloc(sizeof(phase_frame_t));
    frame->phase_id = id;
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
    phase_driver.action_error = false;
    phase_driver.non_fatal_error = false;
    phase_driver.phase_stack = create_array();
    phase_driver.passes_time_frames = array_init(20);
    phase_driver.cycles_time_frames = array_init(20);
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

bool _ccn_mark_apply(void *item) {
    phase_frame_t *top = _top_frame();
    for (int i = 0; i < array_size(top->marks); ++i) {
        cycle_mark_t *mark = array_get(top->marks, i);
        if (mark->node == item) {
            mark->notified = false;
            return true;
        }
    }
    return false;
}

// TODO allow user to use this function instead of the safer ones.
bool _ccn_mark_remove(void *item) {
    phase_frame_t *top = _top_frame();
    for (int i = 0; i < array_size(top->marks); ++i) {
        cycle_mark_t *mark = array_get(top->marks, i);
        if (mark->node == item) {
            mark->notified = true;
            return true;
        }
    }
    return false;
}




void _ccn_start_phase(char *id) {
    printf("Starting phase: %s\n", id);
    _push_frame(id);
}

void _ccn_end_phase(char *id) {
    printf("Ending phase:   %s\n", id);
    _pop_frame();
}

void _ccn_new_cycle_time_frame(char *id, double time_sec) {
    phase_frame_t *top = _top_frame();
    time_frame_t *time_frame = mem_alloc(sizeof(time_frame_t));
    time_frame->id = id;
    time_frame->time_sec = time_sec;
    time_frame->parent_phase = top->phase_id;
    array_append(phase_driver.cycles_time_frames, time_frame);

}


void _ccn_new_passes_time_frame(char *id, double time_sec) {
    phase_frame_t *top = _top_frame();
    time_frame_t *time_frame = mem_alloc(sizeof(time_frame_t));
    time_frame->id = id;
    time_frame->time_sec = time_sec;
    time_frame->parent_phase = top->phase_id;
    array_append(phase_driver.passes_time_frames, time_frame);
}

int compare_time_frame_inverse(const void *a, const void *b) {
    const time_frame_t *pass_a = *((time_frame_t**)a);
    const time_frame_t *pass_b = *((time_frame_t**)b);
    if (pass_a->time_sec > pass_b->time_sec) {
        return -1;
    } else if (pass_a->time_sec < pass_b->time_sec) {
        return 1;
    }
    return 0;
}

void _print_top_n_time(int n) {
    array *passes_times = phase_driver.passes_time_frames;
    array *cycles_times = phase_driver.cycles_time_frames;
    array_sort(passes_times, compare_time_frame_inverse);
    array_sort(cycles_times, compare_time_frame_inverse);
    if (n > array_size(passes_times))
        n = array_size(passes_times);

    printf("\n");
    printf("-------------------------------------------------\n");
    printf("Time statistic:\n\n");

    printf("Passes:\n");
    printf("Time(s)  | name of pass\n");
    for (int i = 0; i < n; ++i) {
        time_frame_t *time_frame = array_get(passes_times, i);
        printf("%f | %s.%s\n", time_frame->time_sec, time_frame->parent_phase, time_frame->id);
    }
    printf("\n");
    if (n > array_size(cycles_times))
        n = array_size(cycles_times);
    printf("Cycles:\n");
    printf("Time(s)  | name of cycle\n");
    for (int i = 0; i < n; ++i) {
        time_frame_t *time_frame = array_get(cycles_times, i);
        printf("%f | %s.%s\n", time_frame->time_sec, time_frame->parent_phase, time_frame->id);
    }
    printf("---------------------------------------------------------------------------------\n\n");

}