#include "lib/set_implementations.h"
#include "lib/internal_copy_functions.h"
#include "lib/internal_key_functions.h"

CCNset_t *ccn_set_string_create(size_t size) {
    return ccn_set_create_with_size(id_key, id_copy, size);
}