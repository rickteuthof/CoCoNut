#include <stdio.h>
#include "generated/enum.h"
#include "generated/trav-core.h"
#include "lib/memory.h"
#include "lib/print.h"
// Stack of traversals, so that new traversals can be started inside other traversals. 
static struct TravStack *current_traversal;
// Replacement node holder
NodeType node_replacement_type;
void *node_replacement;
struct TravStack {
    struct TravStack *prev;
    TraversalType current;
};

void CCNtrav_push(TraversalType trav) {
    struct TravStack *new = (struct TravStack*)mem_alloc(sizeof(struct TravStack));
    new->current = trav;
    new->prev = current_traversal;
    current_traversal = new;
}

void CCNtrav_pop(void) {
    if (current_traversal == NULL) {
        print_user_error("traversal-driver", "Cannot pop of empty traversal stack.");
        return;
    }
    struct TravStack *prev = current_traversal->prev;
    mem_free(current_traversal);
    current_traversal = prev;
}

TraversalType trav_current(void) {
    return current_traversal->current;
}


