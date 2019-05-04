
#include "core/internal_phase_functions.h"

void ccn_notify_cycle() {
    phase_frame_t *top = _top_frame();
    top->cycle_notified = true;
}