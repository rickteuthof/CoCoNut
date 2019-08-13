// Hash: da1486863569ad210a4555708de59ea2
#pragma once

typedef struct Decl Decl;
typedef struct Decls Decls;
typedef struct Decls {
    struct Decl *decl;
    struct Decls *next;
} Decls;

