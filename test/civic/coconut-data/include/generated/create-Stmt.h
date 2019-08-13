// Hash: bb6639b82c8f18c2af9886944317b845
#pragma once
#include "lib/memory.h"
#include "generated/ast.h"

struct Stmt *create_Stmt_DoWhile(struct DoWhile *_DoWhile);

struct Stmt *create_Stmt_For(struct For *_For);

struct Stmt *create_Stmt_FunCall(struct FunCall *_FunCall);

struct Stmt *create_Stmt_IfElse(struct IfElse *_IfElse);

struct Stmt *create_Stmt_Return(struct Return *_Return);

struct Stmt *create_Stmt_VarLet(struct VarLet *_VarLet);

struct Stmt *create_Stmt_While(struct While *_While);


