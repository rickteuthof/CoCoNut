#include "lib/set.h"
#include "lib/memory.h"

#include <assert.h>

static const int INITIAL_SET_SIZE = 20;



CCNset_t *ccn_set_create(char *(*key_func)(void *), void *(*copy_func)(const void*)) {
    assert(key_func != NULL);
    CCNset_t *set = (CCNset_t *)mem_alloc(sizeof(CCNset_t));

    set->size = 0;
    set->hash_map = smap_init(INITIAL_SET_SIZE);
    set->key_func = key_func;
    set->copy_func = copy_func;

    return set;
}

bool ccn_set_insert(CCNset_t *set, void *item) {
    assert(set != NULL && item != NULL);
    char *key = set->key_func(item);
    void *val = smap_retrieve(set->hash_map, key);

    if (val != NULL) {
        // Item already in set.
        return false;
    }

    smap_insert(set->hash_map, key, item);
    set->size++;
    return true;

}

size_t ccn_set_size(CCNset_t *set) {
    assert(set != NULL);
    return set->size;
}

bool ccn_set_contains(CCNset_t *set, void *item) {
    assert(set != NULL && item != NULL);
    char *key = set->key_func(item);

    return smap_retrieve(set->hash_map, key) != NULL;
}

void ccn_set_remove(CCNset_t *set, void *item);

CCNset_t *ccn_set_copy(CCNset_t *target) {
    assert(target != NULL);
    CCNset_t *new_set = ccn_set_create(target->key_func, target->copy_func);
    array *values = smap_values(target->hash_map);
    for (int i = 0; i < array_size(values); i++) {
        ccn_set_insert(new_set, new_set->copy_func(array_get(values, i)));
    }
    return new_set;
}

void *ccn_set_get(CCNset_t *set, void *item) {
    assert(set != NULL && item != NULL);

    return smap_retrieve(set->hash_map, set->key_func(item));
}


CCNset_t *ccn_set_intersect(CCNset_t *first, CCNset_t* second) {
    assert(first != NULL && second != NULL);

    if (first->key_func != second->key_func)
        return NULL;

    CCNset_t *new_set = ccn_set_create(first->key_func, first->copy_func);
    array *values = smap_values(first->hash_map);

    for (int i = 0; i < array_size(values); i++) {
        void *value = array_get(values, i);
        if (ccn_set_contains(second, value)) {
            ccn_set_insert(new_set, value);
        }
    }

    return new_set;
}

CCNset_t *ccn_set_union(CCNset_t *first, CCNset_t *second) {
    assert(first != NULL && second != NULL);

    if (first->key_func != second->key_func)
        return NULL;

    CCNset_t *new_set = ccn_set_copy(first);
    array *values = smap_values(second->hash_map);
    for (int i = 0; i < array_size(values); i++) {
        void *value = array_get(values, i);
        if (!ccn_set_contains(new_set, value)) {
            ccn_set_insert(new_set, second->copy_func(value));
        }
    }

    return new_set;
}

CCNset_t *ccn_set_difference(CCNset_t *first, CCNset_t *second) {
    assert(first != NULL && second != NULL);

    if (first->key_func != second->key_func)
        return NULL;

    CCNset_t *new_set = ccn_set_create(first->key_func, first->copy_func);
    array *values = smap_values(first->hash_map);

    for (int i = 0; i < array_size(values); i++) {
        void *value = array_get(values, i);
        if (!ccn_set_contains(second, value)) {
            ccn_set_insert(new_set, first->copy_func(value));
        }
    }

    return new_set;
}
