typedef struct command_options {
    bool profiling;
    bool break_inspect_points;
    bool consistcheck;
    bool serialise;
    bool ast_memory_manager;
    bool memory_reporter;
    bool garbage_collection;
} command_options_t;

extern command_options_t global_options;