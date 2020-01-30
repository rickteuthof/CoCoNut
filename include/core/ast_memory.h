#ifndef _AST_MEMORY_H_
#define _AST_MEMORY_H_

#include <stdlib.h>

enum entry_type {
    ast_empty,
    ast_string,
	ast_node,
};

extern enum entry_type entry_type;

typedef struct ast_memory_manager ast_memory_manager;
typedef struct memory_statistics memory_statistics;

void _ccn_setup_ast_memory_manager();
void expand_ast_memory_manager();
void _ccn_free_ast_memory_manager();

int add_ast_memory_manager_entry(void *ptr, size_t size, enum entry_type type);
int remove_ast_memory_manager_entry(void *ptr);
int mark_ast_memory_manager_entry(void *ptr);

int reset_ast_memory_manager_entries(char* id);
void garbage_collection_sweep();
void report_all_leaks();

//void leak_ast_memory_manager_entry; 

void *ast_alloc(size_t size, enum entry_type type);
void ast_free(void *ptr);
void *ast_copy(const void *src, size_t size);

void start_pass();
void start_phase();


/* Pass related */
size_t stop_size_alloc_pass();
int stop_num_alloc_pass();
size_t stop_size_dealloc_pass();
int stop_num_dealloc_pass();

/* Phase related */
size_t stop_size_alloc_phase();
int stop_num_alloc_phase();
size_t stop_size_dealloc_phase();
int stop_num_dealloc_phase();
int stop_num_marked_phase();

/* Total related */
size_t stop_size_alloc_total();
int stop_num_alloc_total();
size_t stop_size_dealloc_total();
int stop_num_dealloc_total();

#endif /*_AST_MEMORY_H */



