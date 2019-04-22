#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/errors.h"
#include "lib/print.h"

void *mem_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        print_user_error("memory", "malloc allocation returned NULL.");
        exit(MALLOC_NULL);
    }
    return ptr;
}

void mem_free(void *ptr) {
    if (ptr != NULL)
        free(ptr);
}

void *mem_copy(const void *src, size_t size) {
    void *new = mem_alloc(size);
    memcpy(new, src, size);
    return new;
}
