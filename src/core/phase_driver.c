#include "core/internal_phase_functions.h"
#include "core/break_inspect_points.h"
#include "core/ast_memory.h"

#include "generated/action_handlers.h"

void ccn_phase_driver_init() {
#ifdef CCN_ENABLE_MEM_MANAGER
    _ccn_setup_ast_memory_manager();
#endif
    //_ccn_setup_ast_memory_manager();
    return _initialize_phase_driver();
}

void ccn_phase_driver_destroy() {
#ifdef CCN_ENABLE_MEM_MANAGER
    _ccn_free_ast_memory_manager();
#endif
    return phase_driver_destroy();
}

bool ccn_set_breakpoint(char *breakpoint) {
    _ccn_set_breakpoint(breakpoint);
}

bool ccn_set_inspectpoint(char *inspect) {
    _ccn_set_inspect_point(inspect);
}

void ccn_phase_driver_start() {
#ifdef CCN_ENABLE_MEM_MANAGER
    _cnn_pre_phase_memory();
#endif
    _ccn_phase_driver_start();
}
void ccn_print_time_statistics(int n) { 
    _ccn_print_top_n_time(n);
#ifdef CCN_ENABLE_MEM_MANAGER
    _ccn_print_top_n_memory(n);
#endif
    
}

void ccn_print_mem_statistics(int m) {

}

void ccn_print_statistic(int n, int m) {
    ccn_print_time_statistics(n);
    ccn_print_time_statistics(m);
}