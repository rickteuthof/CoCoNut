// Hash: 335492ed82f8520c39ccbce6a5739af7
#pragma once

typedef struct FunDef FunDef;
typedef struct LocalFunDef LocalFunDef;
typedef struct LocalFunDef {
    struct FunDef *decl;
    struct LocalFunDef *next;
} LocalFunDef;

