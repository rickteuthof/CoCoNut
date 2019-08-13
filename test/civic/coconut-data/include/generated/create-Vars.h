// Hash: e7edc9c998e6633c941feaada999a32e
#pragma once
#include "lib/memory.h"
#include "generated/ast.h"

struct Vars *create_Vars_Var(struct Var *_Var);

struct Vars *create_Vars_VarDec(struct VarDec *_VarDec);

struct Vars *create_Vars_VarLet(struct VarLet *_VarLet);


