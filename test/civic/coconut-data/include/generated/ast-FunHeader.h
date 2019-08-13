// Hash: 33e19f933fee95125167d08907d344d2
#pragma once

typedef struct Param Param;
#include "generated/enum.h"
typedef struct FunHeader {
    struct Param *params;
    char * id;
    BasicType rettype;
} FunHeader;

