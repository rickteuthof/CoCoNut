// Hash: e7edc9c998e6633c941feaada999a32e
#pragma once

// Forward declarations of children.
typedef struct Var Var;
typedef struct VarDec VarDec;
typedef struct VarLet VarLet;
// Nodeset Vars
typedef enum { NS_Vars_Var, NS_Vars_VarDec, NS_Vars_VarLet, } NS_Vars_enum;
typedef struct Vars {
    union {
        struct Var *val_Var;
        struct VarDec *val_VarDec;
        struct VarLet *val_VarLet;
    } value;
    NS_Vars_enum type;
} Vars;


