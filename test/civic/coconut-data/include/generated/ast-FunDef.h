// Hash: 1e4fc8c57864026894e956f2ce63ce36
#pragma once

typedef struct FunBody FunBody;
typedef struct FunHeader FunHeader;
typedef struct FunSymbol FunSymbol;
typedef struct FunDef FunDef;
typedef struct Symbol Symbol;
#include <stdbool.h>
typedef struct FunDef {
    struct FunBody *funbody;
    struct FunHeader *funheader;
    struct FunSymbol *funsymbol;
    struct FunDef *next;
    struct Symbol *symbol;
    bool export;
    bool external;
} FunDef;

