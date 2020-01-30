#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/errors.h"
#include "lib/print.h"
#include "lib/str.h"
#include "lib/smap.h"

#include "core/ast_memory.h"
#include "core/str.h"

#define AST_ENRTYSIZE 150  

static ast_memory_manager *head;
static memory_statistics *stat;

enum ast_status{empty, unmarked, marked, new, leak};

struct ast_memory_manager
{
	void *pointer[AST_ENRTYSIZE];
	size_t size[AST_ENRTYSIZE];
	enum ast_status status[AST_ENRTYSIZE];
	enum entry_type type[AST_ENRTYSIZE];
	char* build_entry[AST_ENRTYSIZE];
	char* leak_entry[AST_ENRTYSIZE];
	ast_memory_manager *next;
};

struct memory_statistics
{
	size_t total_allocated;
	size_t total_deallocated;
	size_t phase_allocated;
	size_t phase_deallocated;
	size_t pass_allocated;
	size_t pass_deallocated;
	
	int total_num_alloc;
	int total_num_free;
	int phase_num_alloc;
	int phase_num_free;
	int pass_num_alloc;
	int pass_num_free;
	int marked_num;
};


void _ccn_setup_ast_memory_manager(){
	ast_memory_manager *ptr = malloc(sizeof(ast_memory_manager));
	memory_statistics *stt = malloc(sizeof(memory_statistics));
	
	stt->total_allocated = 0;
	stt->total_deallocated = 0;
	stt->phase_allocated = 0;
	stt->phase_deallocated = 0;
	stt->pass_allocated = 0;
	stt->pass_deallocated = 0;
	stt->total_num_alloc = 0;
	stt->total_num_free = 0;
	stt->phase_num_alloc= 0;
	stt->phase_num_free = 0;
	stt->pass_num_alloc = 0;
	stt->pass_num_free = 0;
	stt->marked_num = 0;

	memset(ptr->status, empty, AST_ENRTYSIZE*sizeof(ptr->status[0]));
	memset(ptr->type, ast_empty, AST_ENRTYSIZE*sizeof(ptr->status[0]));
	memset(ptr->size, 0, AST_ENRTYSIZE*sizeof(ptr->size[0]));
	memset(ptr->pointer, NULL, AST_ENRTYSIZE*sizeof(ptr->pointer[0]));
	memset(ptr->build_entry, NULL, AST_ENRTYSIZE*sizeof(ptr->build_entry[0]));
	memset(ptr->leak_entry, NULL, AST_ENRTYSIZE*sizeof(ptr->leak_entry[0]));
	ptr->next = NULL;
	head = ptr;
	stat = stt;
	return;
}

void expand_ast_memory_manager(){
	ast_memory_manager *tmp = head;
	ast_memory_manager *ptr = malloc(sizeof(ast_memory_manager));
	memset(ptr->status, empty, AST_ENRTYSIZE*sizeof(ptr->status[0]));
	memset(ptr->type, ast_empty, AST_ENRTYSIZE*sizeof(ptr->status[0]));
	memset(ptr->size, 0, AST_ENRTYSIZE*sizeof(ptr->size[0]));
	memset(ptr->pointer, NULL, AST_ENRTYSIZE*sizeof(ptr->pointer[0]));
	memset(ptr->build_entry, NULL, AST_ENRTYSIZE*sizeof(ptr->build_entry[0]));
	memset(ptr->leak_entry, NULL, AST_ENRTYSIZE*sizeof(ptr->leak_entry[0]));
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = ptr;
	return;
}

int add_ast_memory_manager_entry(void *ptr, size_t size, enum entry_type type){
	int location = 0;
	int empty_found = 0;
	ast_memory_manager *tmp = head;
	while(empty_found == 0){
		if(tmp->status[location] == empty){
			empty_found = 1;
		} else {
			if(location < AST_ENRTYSIZE-1){
				location++;
			} else {
				if(tmp->next != NULL){
					continue;
				} else {
					expand_ast_memory_manager();
				}
				tmp = tmp->next;
				location = 0;
			}
		}
	}
	alloc_statistics(size);
	tmp->status[location] = new;
	tmp->size[location] = size;
	tmp->pointer[location] = ptr;
	tmp->type[location] = type;
	return 1;
}

int mark_ast_memory_manager_entry(void *ptr){
	printf("A start has been made\n");
	int location = 0;
	int found = 0;
	ast_memory_manager *tmp = head;
	while(found == 0){
		if(tmp->status[location] == unmarked & tmp->pointer[location] == ptr){
			tmp->status[location] = marked;
			stat->marked_num += 1;
			printf("number of marked : %d\n", stat->marked_num);
			printf("Match found for pointer %p\n", ptr);
			return 0;
		}
		else if(tmp->status[location] == marked & tmp->pointer[location] == ptr){
			//For error
			printf("Dupplicate child error %p\n", ptr);
			return 1;
		} else {
			if(location < AST_ENRTYSIZE-1){
				location++;
			} else {
				if(tmp->next == NULL){
					return 0;
				}
				tmp = tmp->next;
				location = 0;	
			}
		}
	}
	return 0;
}

int reset_ast_memory_manager_entries(char* id){

	char* def = "Unkown location";
	if(id == NULL){
		id = def;
	}

	printf("I do start\n");
	int location = 0;
	ast_memory_manager *tmp = head;
	while(true){
		printf("location : %d %d\n", location, tmp->status[location]);
		if(tmp->status[location] == new){
			//printf("records its status\n");
			tmp->build_entry[location] = copy_string(id);
			//printf("finished its status\n");
		} 
		else if(tmp->status[location] == unmarked){
			tmp->status[location] = leak;
			if(tmp->leak_entry[location] != NULL){
				printf("Leak for the second time error\n");
			}
			tmp->leak_entry[location] = copy_string(id);
		} 
		
		if(tmp->status[location] != leak && tmp->status[location] != empty){
			tmp->status[location] = unmarked;
		}

		if(location < AST_ENRTYSIZE-1){
			location++;
		} else {
			if(tmp->next == NULL){
				return 0;
			}
			tmp = tmp->next;
			location = 0;	
		}
		//printf("location : %d %d\n", location, tmp->status[location]);
	}
	return 0;
}

void report_all_leaks(){
	int location = 0;
	int leak_num = 0;
	ast_memory_manager *tmp = head;
	while(true){
		printf("repleak location : %d %d\n", location, tmp->status[location]);
		if(tmp->status[location] == leak){
			//dealloc_statistics(tmp->size[location]);
			leak_num++;
			printf("Leak entry %d\n", leak_num);
			printf("Pointer address %p\n", tmp->pointer[location]);
			printf("mem Type entry %d\n", tmp->type[location]);
			printf("Size entry %lu\n", tmp->size[location]);
			printf("Allocated during %s\n", tmp->build_entry[location]);
			printf("Leak during %s\n\n", tmp->leak_entry[location]);
			// tmp->status[location] = empty;
			// tmp->type[location] = ast_empty;
			// tmp->size[location] = 0;
			// tmp->pointer[location] = NULL;
		}
		
		if(location < AST_ENRTYSIZE-1){
			//printf("Hello\n");
			location++;
		} else {
			if(tmp->next == NULL){
				return;
			}
			tmp = tmp->next;
			location = 0;	
		}
	}
	return;
}

void garbage_collection_sweep(){
	int location = 0;
	ast_memory_manager *tmp = head;
	while(true){
		if(tmp->status[location] == unmarked){
			dealloc_statistics(tmp->size[location]);
			tmp->status[location] = empty;
			tmp->type[location] = ast_empty;
			tmp->size[location] = 0;
			tmp->pointer[location] = NULL;
		} else if(tmp->status[location] == marked || tmp->status[location] == new)
		{
			tmp->status[location] = unmarked;
		}
		
		if(location < AST_ENRTYSIZE-1){
			location++;
		} else {
			if(tmp->next == NULL){
				return;
			}
			tmp = tmp->next;
			location = 0;	
		}
	}
	return;
}

int remove_ast_memory_manager_entry(void *ptr){
	int location = 0;
	int found = 0;
	ast_memory_manager *tmp = head;
	while(found == 0){
		if(tmp->status[location] != empty & tmp->pointer[location] == ptr){
			found = 1;
			
		} else {
			if(location < AST_ENRTYSIZE-1){
				location++;
			} else {
				if(tmp->next == NULL){
					return 0;
				}
				tmp = tmp->next;
				location = 0;	
			}
		}
	}
	dealloc_statistics(tmp->size[location]);
	tmp->status[location] = empty;
	tmp->type[location] = ast_empty;
	tmp->size[location] = 0;
	tmp->pointer[location] = NULL;
	if(tmp->build_entry[location] != NULL){
		free(tmp->build_entry[location]);
	}
	return 0;
}

void _ccn_free_ast_memory_manager()
{
	int location = 0;
	free(stat);
	ast_memory_manager *tmp = head;
	ast_memory_manager *tmp2;
	
	while(1){
		if(tmp->status[location] != empty){
			free((void *)tmp->pointer[location]);
			tmp->status[location] = empty;
			tmp->pointer[location] = NULL;
		}
		if(location < AST_ENRTYSIZE-1){
			location++;
		} else {
			if(tmp->next == NULL){
				free(tmp);
				return;
			}
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
			location = 0;
		}
	}
	return;
}

void start_pass()
{
	stat->pass_allocated = 0;
	stat->pass_deallocated = 0;
	stat->pass_num_alloc = 0;
	stat->pass_num_free = 0;
	stat->marked_num == 0;
}

void start_phase()
{
	stat->phase_allocated = 0;
	stat->phase_deallocated = 0;
	stat->phase_num_alloc = 0;
	stat->phase_num_free = 0;
	stat->marked_num = 0;
}

/* Pass Related function */

size_t stop_size_alloc_pass()
{
	return stat->pass_allocated;
}

int stop_num_alloc_pass()
{
	return stat->pass_num_alloc;
}

size_t stop_size_dealloc_pass()
{
	return stat->pass_deallocated;
}

int stop_num_dealloc_pass()
{
	return stat->pass_num_free;
}

/* Phase Related function */

size_t stop_size_alloc_phase()
{
	return stat->phase_allocated;
}

int stop_num_alloc_phase()
{
	return stat->phase_num_alloc;
}

size_t stop_size_dealloc_phase()
{
	return stat->phase_deallocated;
}

int stop_num_dealloc_phase()
{
	return stat->phase_num_free;
}

int stop_num_marked_phase()
{
	return stat->marked_num;
}

/* Total Related function */

size_t stop_size_alloc_total()
{
	return stat->total_allocated;
}

int stop_num_alloc_total()
{
	return stat->total_num_alloc;
}

size_t stop_size_dealloc_total()
{
	return stat->total_deallocated;
}

int stop_num_dealloc_total()
{
	return stat->total_num_free;
}

void alloc_statistics(size_t size)
{
	//printf("ALLOCATION BRUH %u\n", size);
	stat->pass_num_alloc += 1;
	stat->phase_num_alloc += 1;
	stat->total_num_alloc += 1;
	stat->pass_allocated += size;
	stat->phase_allocated += size;
	stat->total_allocated += size;
}

void dealloc_statistics(size_t size)
{
	stat->pass_num_free += 1;
	stat->phase_num_free += 1;
	stat->total_num_free += 1;
	stat->pass_deallocated += size;
	stat->phase_deallocated += size;
	stat->total_deallocated += size;
}

void *ast_alloc(size_t size, enum entry_type type)
{
	void *ptr = malloc(size);

    if (ptr == NULL) {
        print_user_error("memory", "malloc allocation returned NULL.");
        exit(MALLOC_NULL);
    }
	add_ast_memory_manager_entry(ptr, size, type);
    return ptr;
}

void *ast_copy(const void *src, size_t size) 
{
    void *new = malloc(size);
    memcpy(new, src, size);
	add_ast_memory_manager_entry(new, size, ast_node);
    return new;
}

void ast_free(void *ptr)
{
	if (ptr != NULL){
		remove_ast_memory_manager_entry(ptr);
        free(ptr);
	}
	
    return ptr;
}