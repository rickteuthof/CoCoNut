#include <stddef.h>

void ccn_phase_driver_init();
void ccn_phase_driver_destroy();
void ccn_set_time_items_printed(size_t n);
bool ccn_set_breakpoint(char *breakpoint);
bool ccn_set_inspect_point(char *inspect);
void ccn_phase_driver_start();
