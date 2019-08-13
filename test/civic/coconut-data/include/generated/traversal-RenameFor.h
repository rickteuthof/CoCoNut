// Hash: 4af5bd1fabad7502bca5d6e49bbfef6c
#pragma once

#include "generated/ast.h"
#include "generated/trav-For.h"
#include "generated/trav-Var.h"
#include "generated/trav-VarLet.h"
typedef struct Info Info;
Info *RenameFor_createinfo(void);
void RenameFor_freeinfo(Info *);
void RenameFor_For(For *node, Info *info);
void RenameFor_Var(Var *node, Info *info);
void RenameFor_VarLet(VarLet *node, Info *info);

