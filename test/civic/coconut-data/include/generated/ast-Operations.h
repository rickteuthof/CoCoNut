// Hash: 1604aaf06d8e16acccd979c8275f8e32
#pragma once

// Forward declarations of children.
typedef struct BinOp BinOp;
typedef struct MonOp MonOp;
// Nodeset Operations
typedef enum { NS_Operations_BinOp, NS_Operations_MonOp, } NS_Operations_enum;
typedef struct Operations {
    union {
        struct BinOp *val_BinOp;
        struct MonOp *val_MonOp;
    } value;
    NS_Operations_enum type;
} Operations;


