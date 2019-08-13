// Hash: bb6639b82c8f18c2af9886944317b845
#pragma once

// Forward declarations of children.
typedef struct DoWhile DoWhile;
typedef struct For For;
typedef struct FunCall FunCall;
typedef struct IfElse IfElse;
typedef struct Return Return;
typedef struct VarLet VarLet;
typedef struct While While;
// Nodeset Stmt
typedef enum { NS_Stmt_DoWhile, NS_Stmt_For, NS_Stmt_FunCall, NS_Stmt_IfElse, NS_Stmt_Return, NS_Stmt_VarLet, NS_Stmt_While, } NS_Stmt_enum;
typedef struct Stmt {
    union {
        struct DoWhile *val_DoWhile;
        struct For *val_For;
        struct FunCall *val_FunCall;
        struct IfElse *val_IfElse;
        struct Return *val_Return;
        struct VarLet *val_VarLet;
        struct While *val_While;
    } value;
    NS_Stmt_enum type;
} Stmt;


