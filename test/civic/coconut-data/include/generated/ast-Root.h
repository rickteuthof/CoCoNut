// Hash: 70eba40e9dab0c2491717f2637a08068
#pragma once

typedef struct Decls Decls;
typedef struct FunSymbol FunSymbol;
typedef struct Symbol Symbol;
typedef struct Root {
    struct Decls *decls;
    struct FunSymbol *funsymbol;
    struct Symbol *symbol;
} Root;

