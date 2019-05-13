#pragma once
#include "cocogen/ast.h"
#include <stdio.h>

void filegen_init(Config *config, bool list_gen_files_flag);
void filegen_dir(char *out_dir);
FILE *get_fp(char *full_path, char *mode);
char *get_full_path_with_dir(const char *dir, char *filename, char *formatter);
bool is_only_list_files();
Config *_get_ast_definition();
void filegen_generate(char *filename, void (*func)(Config *, FILE *));
void filegen_all_nodes(char *fileformatter,
                       void (*func)(Config *, FILE *, Node *));
void filegen_all_nodesets(char *fileformatter,
                          void (*func)(Config *, FILE *, Nodeset *));

void filegen_all_traversals(char *fileformatter,
                            void (*func)(Config *, FILE *, Traversal *));
void filegen_all_passes(char *fileformatter,
                        void (*func)(Config *, FILE *, Pass *));

void filegen_all_phases(char *fileFormatter,
                        void (*func)(Config *, FILE *, Phase *));

void filegen_phase_subtree(void (*func)(array *));

void filegen_delete_non_generated_filed(ccn_set_t *generated_files, array *directories, ccn_set_t *blacklist);
void filegen_cleanup_old_files(void);
void filegen_cleanup(void);
void print_file_gen(char *full_path);
void add_filename_to_set(char *filename);
bool ensure_dir_exists(char *dirname, int mode);

