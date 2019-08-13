// Hash: af28c29a686569d7ebb3c15611b384d2
#pragma once

typedef struct StmtList StmtList;
typedef struct Stmt Stmt;
typedef struct StmtList {
    struct StmtList *next;
    struct Stmt *stmt;
} StmtList;

