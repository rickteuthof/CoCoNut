#pragma once

/** Set implementation that allows for basic functions on all type of elements.
 * It is a generic set, however every set does not a key function and a copy function.
 * They key function should return a string and be unique for the elements.
 * The element returned by the key function should be allocated.
 * The copy function should be able to make a deep copy of an element.
 */

// TODO: allow for non owning set, by clearing the elements or so.


#include <stdbool.h>
#include <stdlib.h>

#include "lib/smap.h"
#include "lib/memory.h"

typedef struct ccn_set {
    size_t size;
    smap_t *hash_map;
    char *(*key_func)(void *);
    void *(*copy_func)(const void *);
} ccn_set_t;

/** Function to create a set.
 *  The key function should returned a allocated char *.
 *  The copy func should create a deep copy of the item in the set.
 */
ccn_set_t *ccn_set_create(char *(*key_func)(void *),
                         void *(*copy_func)(const void *));

ccn_set_t *ccn_set_create_with_size(char *(*key_func)(void *),
                                   void *(*copy_func)(const void *),
                                   size_t size);

/* Insert item into set, if item is already in set, return false
 * else true.
 */
bool ccn_set_insert(ccn_set_t *set, void *item);
size_t ccn_set_size(ccn_set_t *set);

/* Checks if the item is contained in the set. */
bool ccn_set_contains(ccn_set_t *set, void *item);
void ccn_set_remove(ccn_set_t *set, void *item);

/* Creates a deep copy of the target set. */
ccn_set_t *ccn_set_copy(ccn_set_t *target);

/* Function to free a set with a special free function
 * for the elements in the set.
 */
void ccn_set_free_with_func(ccn_set_t *set, void (*free_func)(void *));

/* Wrapper around using the mem_free function for you set free. */
inline void ccn_set_free(ccn_set_t *set) {
    ccn_set_free_with_func(set, mem_free);
}

/* Returns an array of all the values in the set.
 * The values are NOT copied.
 */
array *ccn_set_values(ccn_set_t *set);

void *ccn_set_get(ccn_set_t *set, void *item);

/* Returns a new set that is the intersection of a and b. */
ccn_set_t *ccn_set_intersect(ccn_set_t *a, ccn_set_t *b);

/* Returns a new set that is the union of a and b. */
ccn_set_t *ccn_set_union(ccn_set_t *a, ccn_set_t *b);

/* Return a new set that is the difference (a-b) of a and b. */
ccn_set_t *ccn_set_difference(ccn_set_t *a, ccn_set_t *b);
