#pragma once

/**
 * @file include/cocogen/ast.h
 * @brief The definition of all the types in the internal AST.
 */

#include <stdbool.h>
#include <stdint.h>

#include "lib/array.h"
#include "lib/set.h"

typedef struct SetExpr SetExpr;

typedef struct NodeCommonInfo {
    // Needed for Pass, Traversal, Enum, Node, Nodeset,
    // contains the unique identifier for all data needed in codegen.
    char *hash;
} NodeCommonInfo;

enum NodeType { NT_node, NT_nodeset };

enum MandatoryPhaseType { MP_single, MP_range };

enum AttrType {
    AT_int,
    AT_uint,
    AT_int8,
    AT_int16,
    AT_int32,
    AT_int64,
    AT_uint8,
    AT_uint16,
    AT_uint32,
    AT_uint64,

    AT_float,
    AT_double,

    AT_bool,
    AT_string,
    AT_link_or_enum,
    AT_link,
    AT_enum,
};

enum AttrValueType {
    AV_string,
    AV_int,
    AV_uint,
    AV_float,
    AV_double,
    AV_bool,
    AV_id
};

enum PhaseType { PH_subphases, PH_passes };

enum PhaseLeafType { PL_pass, PL_traversal };

/**
 * @brief The possible operations to perform on two set expressions. @see SetExpr
 */
enum SetOperator {
     SET_UNION,
     SET_INTERSECT,
     SET_DIFFERENCE
};

enum SetExprType {
     SET_REFERENCE,
     SET_NODE_IDS,
     SET_OPERATION
};

typedef struct Config {
    array *phases;
    array *passes;
    array *traversals;
    array *enums;
    array *nodesets;
    array *nodes;

    struct Node *root_node;
    struct Phase *phase_tree;

    struct NodeCommonInfo *common_info;
} Config;

typedef struct Phase {
    char *id;
    char *info;

    enum PhaseType type;
    bool cycle;
    bool root;

    array *passes;
    array *subphases;

    struct NodeCommonInfo *common_info;
} Phase;

typedef struct PhaseLeaf {
    enum PhaseLeafType type;
    union {
        struct Pass *pass;
        struct Traversal *traversal;
    } value;
} PhaseLeaf;

typedef struct Pass {
    char *id;
    char *info;
    char *func;

    struct NodeCommonInfo *common_info;
} Pass;

typedef struct Traversal {
    char *id;
    char *info;
    char *func;

    union {
        array *nodes;
        SetExpr *expr;
    };

    struct NodeCommonInfo *common_info;
} Traversal;

typedef struct Enum {
    char *id;
    char *prefix;
    char *info;

    array *values;

    struct NodeCommonInfo *common_info;
} Enum;

typedef struct Nodeset {
    char *id;
    char *info;

    // The set expr of this nodeset, will be transformed
    // into an array of nodes.
    union {
        array *nodes;
        SetExpr *expr;
    };

    struct NodeCommonInfo *common_info;
} Nodeset;

typedef struct Node {
    char *id;
    char *info;

    // array of (struct Child *)
    array *children;

    // array of (struct Attr *)
    array *attrs;

    bool root;

    struct NodeCommonInfo *common_info;
} Node;

typedef struct Child {
    int construct;
    int mandatory;
    array *mandatory_phases;
    char *id;
    char *type;

    // One of these becomes a link to the actual child node(set), other NULL
    // after checking the ast.
    struct Node *node;
    struct Nodeset *nodeset;

    struct NodeCommonInfo *common_info;
} Child;

typedef struct PhaseRange {
    char *start;
    char *end;

    struct NodeCommonInfo *common_info;
} PhaseRange;

typedef struct MandatoryPhase {
    enum MandatoryPhaseType type;
    int negation;

    union {
        struct PhaseRange *range;
        char *single;
    } value;

    struct NodeCommonInfo *common_info;
} MandatoryPhase;

typedef struct Attr {
    int construct;
    enum AttrType type;
    char *type_id;
    char *id;
    struct AttrValue *default_value;

    struct NodeCommonInfo *common_info;
} Attr;

typedef struct AttrValue {
    enum AttrValueType type;
    union {
        uint64_t uint_value;
        int64_t int_value;
        float float_value;
        double double_value;
        char *string_value;
        bool bool_value;
    } value;

    struct NodeCommonInfo *common_info;
} AttrValue;

/**
 * @struct SetOperation
 * @brief The structure to store a set operation on two expressions.
 *
 * @details A set operation is an operation, like a UNION or INTERSECT
 *  on two set expressions.
 */
typedef struct SetOperation {
     enum SetOperator operator;
     SetExpr *left_child;
     SetExpr *right_child;
     struct NodeCommonInfo *common_info;
} SetOperation;


/**
 * @struct SetExpr
 * @brief The structure to store an internal set expression.
 *
 * @details An internal set expression can be of three possible types:
 *   -# ref_id:
 *        Reference to a defined nodeset.
 *   -# id_set:
 *        A set of node ids, which is defined inline, so by placing between
 *        {} brackets.
 *   -# operation:
 *        A set operation on two node sets. This node set will be the result
 *        of that operation.
 *
 * All these types will be transformed into an array of nodes,
 * which can be found in the nodes array.
 */
struct SetExpr {
    enum SetExprType type;

    union {
        char *ref_id;
        CCNset_t *id_set;
        SetOperation *operation;
    };

    struct NodeCommonInfo *common_info;
};
