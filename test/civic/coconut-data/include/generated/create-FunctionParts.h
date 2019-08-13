// Hash: 782f9b0b6daa7e2b74e6825788ce728f
#pragma once
#include "lib/memory.h"
#include "generated/ast.h"

struct FunctionParts *create_FunctionParts_FunBody(struct FunBody *_FunBody);

struct FunctionParts *create_FunctionParts_FunDef(struct FunDef *_FunDef);

struct FunctionParts *create_FunctionParts_FunHeader(struct FunHeader *_FunHeader);

struct FunctionParts *create_FunctionParts_Param(struct Param *_Param);


