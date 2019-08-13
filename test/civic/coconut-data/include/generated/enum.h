#pragma once
typedef enum {
   NT_BinOp,
   NT_BoolConst,
   NT_Cast,
   NT_Decls,
   NT_DoWhile,
   NT_ExprList,
   NT_FloatConst,
   NT_For,
   NT_FunBody,
   NT_FunCall,
   NT_FunDef,
   NT_FunHeader,
   NT_FunSymbol,
   NT_GlobalDec,
   NT_GlobalDef,
   NT_IfElse,
   NT_IntConst,
   NT_LocalFunDef,
   NT_MonOp,
   NT_Param,
   NT_Return,
   NT_Root,
   NT_StmtList,
   NT_Symbol,
   NT_Ternary,
   NT_Var,
   NT_VarDec,
   NT_VarLet,
   NT_While,
   NT_Constants,
   NT_Decl,
   NT_Expr,
   NT_FunctionParts,
   NT_Operations,
   NT_Stmt,
   NT_Vars,
} NodeType;

typedef enum {
   TRAV_ByteCode,
   TRAV_Context,
   TRAV_Print,
   TRAV_Refactor,
   TRAV_RenameFor,
   TRAV_SplitInit,
   TRAV_Symbols,
   TRAV_TypeCheck,
    TRAV_NULL
} TraversalType;

typedef enum {
    BT_bool,
    BT_float,
    BT_int,
    BT_void,
    BT_NULL
} BasicType;

typedef enum {
    BO_add,
    BO_and,
    BO_div,
    BO_eq,
    BO_geq,
    BO_gt,
    BO_leq,
    BO_lt,
    BO_mod,
    BO_mul,
    BO_neq,
    BO_or,
    BO_sub,
    BO_NULL
} BinOpEnum;

typedef enum {
    MO_neg,
    MO_not,
    MO_NULL
} MonOpEnum;


