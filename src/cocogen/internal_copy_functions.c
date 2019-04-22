#include "cocogen/ast.h"

#include <assert.h>
#include <string.h>

#include "lib/memory.h"

void *id_copy(const void *item) {
    assert(item != NULL);
    char *original = (char*)item;
    char *copy = mem_copy(original, strlen(original) + 1);
    return copy;
}
