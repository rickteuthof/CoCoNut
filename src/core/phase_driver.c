#include "core/internal_phase_functions.h"
#include "core/break_inspect_points.h"
#include "generated/"

void ccn_phase_driver_init() {
    return _initialize_phase_driver();
}

void ccn_phase_driver_destroy() {
    return phase_driver_destroy();
}


void ccn_set_time_items_printed(size_t n) {
    return ccn_set_print_n(n);
}

bool ccn_set_breakpoint(char *breakpoint) {
    _ccn_set_breakpoint(breakpoint);
}
bool ccn_set_inspect_point(char *inspect) {
    _ccn_set_inspect_point(inspect);
}

void ccn_phase_driver_start() {

}