// Hash: be4c521ad82189ec8e08be8055ccee09
#pragma once

// Forward declarations of children.
typedef struct BoolConst BoolConst;
typedef struct FloatConst FloatConst;
typedef struct IntConst IntConst;
// Nodeset Constants
typedef enum { NS_Constants_BoolConst, NS_Constants_FloatConst, NS_Constants_IntConst, } NS_Constants_enum;
typedef struct Constants {
    union {
        struct BoolConst *val_BoolConst;
        struct FloatConst *val_FloatConst;
        struct IntConst *val_IntConst;
    } value;
    NS_Constants_enum type;
} Constants;


