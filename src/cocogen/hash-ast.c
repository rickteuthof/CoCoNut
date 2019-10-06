/* Module that contains the hashing of the AST.
 * We hash the AST to prevent recompilation of most files that require no change.
 *
 * TODO: Use compiler flags in the hashes as well.
 */


#include "cocogen/hash-ast.h"
#include "cocogen/str-ast.h"

#include "lib/errors.h"
#include "lib/memory.h"
#include "lib/print.h"

#include <mhash.h>


#define hash(a, b)                                                            \
    do {                                                                      \
        mhash(td, a, strlen(a) * sizeof(b));                                  \
    } while (0)
#define hashc(a, b)                                                           \
    do {                                                                      \
        mhash(config_td, a, strlen(a) * sizeof(b));                           \
    } while (0)



static MHASH td;
static MHASH config_td;
static unsigned char hash[17]; /* enough size for MD5 */

static void set_hash(NodeCommonInfo *info, bool config) {
    info->hash = (char *)mem_alloc(
        ((mhash_get_block_size(MHASH_MD5) * 2) + 1) * sizeof(char));
    info->hash[(mhash_get_block_size(MHASH_MD5) * 2)] = '\0';

    // Save the hash.
    for (int i = 0; i < mhash_get_block_size(MHASH_MD5); i++) {
        sprintf(info->hash + (i * 2), "%.2x", hash[i]);
    }
}

static void hash_range_spec(Range_spec_t *spec) {
    hash(spec->inclusive ? "y" : "n", char);
    hash(spec->type, char);
}

static void hash_lifetime(Lifetime_t *lifetime) {
    hash_range_spec(lifetime->start);
    hash_range_spec(lifetime->end);
    for (int i = 0; i < array_size(lifetime->values); i++) {
        hash(array_get(lifetime->values, i), char);
    }
}

static void hash_node(Node *n) {

    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(n->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(n->id, char);
    hash(n->root ? "y" : "n", char);
    for (int i = 0; i < array_size(n->children); ++i) {
        Child *child = array_get(n->children, i);
        hash(child->id, char);
        hash(child->type, char);
        hash(child->construct ? "y" : "n", char);

        // Node children can change to different type without name changes.
        hash(child->node == NULL ? "y" : "n", char);
        hash(child->nodeset == NULL ? "y" : "n", char);

        for (int j = 0; j < array_size(child->lifetimes); ++j) {
            hash_lifetime(array_get(child->lifetimes, j));
        }
    }

    for (int i = 0; i < array_size(n->attrs); ++i) {
        Attr *attr = array_get(n->attrs, i);
        char *attr_type_string = str_attr_type(attr);
        hash(attr->id, char);
        hash(attr_type_string, char);
        hash(attr->construct ? "y" : "n", char);
        if (attr->default_value) {
            AttrValue *val = attr->default_value;

            switch (val->type) {
            case AV_string:
                hash(val->value.string_value, char);
                break;
            case AV_int:
                mhash(td, &val->value.int_value, sizeof(int64_t));
                break;
            case AV_uint:
                mhash(td, &val->value.uint_value, sizeof(uint64_t));
                break;
            case AV_float:
                mhash(td, &val->value.float_value, sizeof(float));
                break;
            case AV_double:
                mhash(td, &val->value.double_value, sizeof(double));
                break;
            case AV_bool:
                hash(val->value.bool_value ? "y" : "n", char);
                break;
            case AV_id:
                hash(val->value.string_value, char);
                break;
            }
        }
        for (int j = 0; j < array_size(attr->lifetimes); j++) {
            hash_lifetime(array_get(attr->lifetimes, j));
        }
        if (attr->type == AT_link) mem_free(attr_type_string);
    }
    for (int i = 0; i < array_size(n->lifetimes); ++i) {
        hash_lifetime(array_get(n->lifetimes, i));
    }

    mhash_deinit(td, hash);
    set_hash(n->common_info, false);
}

static void hash_nodeset(Nodeset *nodeset) {
    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(nodeset->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(nodeset->id, char);

    for (int i = 0; i < array_size(nodeset->nodes); ++i) {
        Node *node = array_get(nodeset->nodes, i);
        hash(node->id, char);
    }

    mhash_deinit(td, hash);
    set_hash(nodeset->common_info, false);
}

static void hash_traversal(Traversal *trav) {
    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(trav->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(trav->id, char);
    if (trav->func)
        hash(trav->func, char);

    for (int i = 0; i < array_size(trav->nodes); ++i) {
        char *node = array_get(trav->nodes, i);
        hash(node, char);
    }

    mhash_deinit(td, hash);
    set_hash(trav->common_info, false);
}

static void hash_phase(Phase *phase) {
    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(phase->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(phase->id, char);
    hash(phase->cycle ? "y" : "n", char);
    hash(phase->start ? "y" : "n", char);
    if (phase->root != NULL) hash(phase->root, char);

    for (int i = 0; i < array_size(phase->actions); ++i) {
        Action *action = array_get(phase->actions, i);
        hash(action->action_owner ? "owner" : "not owner", char);

        switch (action->type) {
        case ACTION_PASS:
            hash("Pass", char);
            hash(((Pass *)action->action)->id, char);
            break;
        case ACTION_TRAVERSAL:
            hash("Trav", char);
            hash(((Traversal *)action->action)->id, char);
            break;
        case ACTION_PHASE:
            hash("Phase", char);
            hash(((Phase *)action->action)->id, char);
            break;
        case ACTION_REFERENCE:
            hash("Ref", char);
            hash(((char *)action->action), char);
            break;
        }
    }

    array *values = ccn_set_values(phase->roots);
    for (int i = 0; i < array_size(values); ++i) {
        char *root = array_get(values, i);
        hash(root, char);
    }
    array_clear(values);
    array_cleanup(values, mem_free);

    mhash_deinit(td, hash);
    set_hash(phase->common_info, false);
}

static void hash_pass(Pass *pass) {
    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(pass->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(pass->id, char);
    if (pass->func)
        hash(pass->func, char);

    array *values = ccn_set_values(pass->roots);
    for (int i = 0; i < array_size(values); ++i) {
        char *root = array_get(values, i);
        hash(root, char);
    }
    array_cleanup(values, NULL);

    mhash_deinit(td, hash);
    set_hash(pass->common_info, false);
}

static void hash_enum(Enum *e) {
    td = mhash_init(MHASH_MD5);
    if (td == MHASH_FAILED) {
        print_error(e->id, "Error generating hashes.");
        exit(HASH_ERROR);
    }

    hash(e->id, char);
    hash(e->prefix, char);

    for (int i = 0; i < array_size(e->values); ++i) {
        char *value = array_get(e->values, i);
        hash(value, char);
    }

    mhash_deinit(td, hash);
    set_hash(e->common_info, false);
}

void hash_config(Config *c) {
    Node *node;
    Nodeset *nodeset;
    Traversal *trav;
    Phase *phase;
    Pass *pass;
    Enum *e;

    config_td = mhash_init(MHASH_MD5);
    if (config_td == MHASH_FAILED) {
        print_internal_error("Creating config hash failed.");
        exit(HASH_ERROR);
    }

    for (int i = 0; i < array_size(c->nodes); ++i) {
        node = array_get(c->nodes, i);
        hash_node(node);
        hashc(node->common_info->hash, char);
    }
    for (int i = 0; i < array_size(c->nodesets); ++i) {
        nodeset = array_get(c->nodesets, i);
        hash_nodeset(nodeset);
        hashc(nodeset->common_info->hash, char);
    }
    for (int i = 0; i < array_size(c->traversals); ++i) {
        trav = array_get(c->traversals, i);
        hash_traversal(trav);
        hashc(trav->common_info->hash, char);
    }
    for (int i = 0; i < array_size(c->phases); ++i) {
        phase = array_get(c->phases, i);
        hash_phase(phase);
        hashc(phase->common_info->hash, char);
    }
    for (int i = 0; i < array_size(c->passes); ++i) {
        pass = array_get(c->passes, i);
        hash_pass(pass);
        hashc(pass->common_info->hash, char);
    }
    for (int i = 0; i < array_size(c->enums); ++i) {
        e = array_get(c->enums, i);
        hash_enum(e);
        hashc(e->common_info->hash, char);
    }

    mhash_deinit(config_td, hash);
    set_hash(c->common_info, true);

    // printf("Config hash is | %s\n", c->common_info->hash);
}
