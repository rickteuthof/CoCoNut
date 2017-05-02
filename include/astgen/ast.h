#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "lib/array.h"

struct NodeCommonInfo {
    int line_start;
    int line_end;
    int column_start;
    int column_end;
};

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

// We define the type for YYLTYPE here,
// to avoid a circular dependency between this header and the parser
struct ParserLocation {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
};

struct Config {
    array *phases;
    array *passes;
    array *traversals;
    array *enums;
    array *nodesets;
    array *nodes;

    struct Node *root_node;
    struct Nodeset *root_nodeset;
    struct Phase *phase_tree;

    struct NodeCommonInfo *common_info;
};

struct Phase {
    char *id;
    char *info;

    enum PhaseType type;
    bool cycle;
    bool root;

    array *passes;
    array *subphases;

    struct NodeCommonInfo *common_info;
};

struct PhaseLeaf {
    enum PhaseLeafType type;
    union {
        struct Pass *pass;
        struct Traversal *traversal;
    } value;
};

struct Pass {
    char *id;
    char *info;
    char *func;

    struct NodeCommonInfo *common_info;
};

struct Traversal {
    char *id;
    char *info;
    char *func;

    array *nodes;

    struct NodeCommonInfo *common_info;
};

struct Enum {
    char *id;
    char *prefix;
    char *info;

    array *values;

    struct NodeCommonInfo *common_info;
};

struct Nodeset {
    char *id;
    char *info;

    // Array of strings transformed into array of Nodes.
    array *nodes;

    bool root;

    struct NodeCommonInfo *common_info;
};

struct Node {
    char *id;
    char *info;

    // array of (struct Child *)
    array *children;

    // array of (struct Attr *)
    array *attrs;

    bool root;

    struct NodeCommonInfo *common_info;
};

struct Child {
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
};

struct PhaseRange {
    char *start;
    char *end;

    struct NodeCommonInfo *common_info;
};

struct MandatoryPhase {
    enum MandatoryPhaseType type;
    int negation;

    union {
        struct PhaseRange *range;
        char *single;
    } value;

    struct NodeCommonInfo *common_info;
};

struct Attr {
    int construct;
    enum AttrType type;
    char *type_id;
    char *id;
    struct AttrValue *default_value;

    struct NodeCommonInfo *common_info;
};

struct AttrValue {
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
};