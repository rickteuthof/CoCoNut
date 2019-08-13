// Hash: a1b06fb9abb037787acc985178482577
#pragma once

// Forward declarations of children.
typedef struct FunDef FunDef;
typedef struct GlobalDec GlobalDec;
typedef struct GlobalDef GlobalDef;
// Nodeset Decl
typedef enum { NS_Decl_FunDef, NS_Decl_GlobalDec, NS_Decl_GlobalDef, } NS_Decl_enum;
typedef struct Decl {
    union {
        struct FunDef *val_FunDef;
        struct GlobalDec *val_GlobalDec;
        struct GlobalDef *val_GlobalDef;
    } value;
    NS_Decl_enum type;
} Decl;


