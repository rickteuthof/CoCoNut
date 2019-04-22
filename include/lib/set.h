#pragma once

#include <stdlib.h>
#include <stdbool.h>

#include "lib/smap.h"

typedef struct CCNset {
    size_t size;
    smap_t *hash_map;
    char *(*key_func)(void *);
    void *(*copy_func)(const void *);
} CCNset_t;


CCNset_t *ccn_set_create(char *(*key_func)(void *), void *(*copy_func)(const void*));
bool ccn_set_insert(CCNset_t *set, void *item);
size_t ccn_set_size(CCNset_t *set);
bool ccn_set_contains(CCNset_t *set, void *item);
void ccn_set_remove(CCNset_t *set, void *item);
CCNset_t *ccn_set_copy(CCNset_t *target);
void *ccn_set_get(CCNset_t *set, void *item);


CCNset_t *ccn_set_intersect(CCNset_t *first, CCNset_t* second);
CCNset_t *ccn_set_union(CCNset_t *first, CCNset_t *second);
CCNset_t *ccn_set_difference(CCNset_t *first, CCNset_t *second);
