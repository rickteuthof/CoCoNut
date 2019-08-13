// Hash: 782f9b0b6daa7e2b74e6825788ce728f
#pragma once

// Forward declarations of children.
typedef struct FunBody FunBody;
typedef struct FunDef FunDef;
typedef struct FunHeader FunHeader;
typedef struct Param Param;
// Nodeset FunctionParts
typedef enum { NS_FunctionParts_FunBody, NS_FunctionParts_FunDef, NS_FunctionParts_FunHeader, NS_FunctionParts_Param, } NS_FunctionParts_enum;
typedef struct FunctionParts {
    union {
        struct FunBody *val_FunBody;
        struct FunDef *val_FunDef;
        struct FunHeader *val_FunHeader;
        struct Param *val_Param;
    } value;
    NS_FunctionParts_enum type;
} FunctionParts;


