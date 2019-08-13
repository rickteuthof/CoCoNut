// Hash: 2a17d582c98658539abe0f791e2036ae
#pragma once

typedef struct Symbol Symbol;
#include <stdbool.h>
typedef struct Symbol {
    struct Symbol *next;
    bool export;
    bool external;
    char * name;
    int offset;
    int scope;
} Symbol;

