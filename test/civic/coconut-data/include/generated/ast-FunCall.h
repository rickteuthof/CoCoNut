// Hash: cc2abd438fff2facf1c543ad95507122
#pragma once

typedef struct ExprList ExprList;
struct FunSymbol;
typedef struct FunCall {
    struct ExprList *params;
    char * id;
    struct FunSymbol * symbol;
} FunCall;

