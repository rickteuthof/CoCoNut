// Hash: b749bf704b901788bcd7cb60caea2822
#pragma once

typedef struct LocalFunDef LocalFunDef;
typedef struct StmtList StmtList;
typedef struct VarDec VarDec;
typedef struct FunBody {
    struct LocalFunDef *localfundef;
    struct StmtList *stmtlist;
    struct VarDec *vardec;
} FunBody;

