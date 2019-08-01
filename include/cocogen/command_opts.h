typedef struct command_options {
    bool profiling;
    bool break_inspect_points;
    bool consistcheck;
    bool serialise;
} command_options_t;

extern command_options_t global_options;