
#include <string.h>
#include <assert.h>

#include "lib/str.h"
#include "lib/memory.h"

char *ccn_str_cpy(const char *source) {
    assert(source != NULL);

    size_t len = strlen(source);
    char *destination = (char *)mem_alloc(len + 1);
    strcpy(destination, source);
    return destination;
}

char *ccn_str_cat(const char *first, const char *second) {
    assert(first != NULL && second != NULL);
    size_t len_first = strlen(first);
    size_t len_second = strlen(second);
    char *result = (char *)mem_alloc(len_first + len_second + 1);
    strcpy(result, first);
    strcat(result, second);
    return result;
}

extern bool ccn_str_equal(const char *first, const char *second) {
    return strcmp(first, second) == 0;
}