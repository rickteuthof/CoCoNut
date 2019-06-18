#include "generated/ast.h"
#include "generated/trav-ast.h"
#include "lib/array.h"
#include "lib/memory.h"
#include "lib/str.h"
#include "lib/imap.h"
#include "lib/smap.h"

#include <stdlib.h>
#include <stdio.h>

struct Info {
    array *hashes;
};

unsigned int *hash_string(char *str) {
    unsigned int *hash = mem_alloc(sizeof(unsigned int));
    *hash = imap_hash_fun(str);
    return hash;
}

char *u_int_to_str(const unsigned int val) {
    char decimal_string[33];
    sprintf(decimal_string, "%d", val);
    return ccn_str_cpy(decimal_string);
}

char *hash_array(array *hashes, char *curr_hash) {
    char decimal_string[33];
    char *hash = mem_alloc(sizeof(char));
    hash[0] = '\0';

    int *h = array_pop(hashes);
    while (h) {
        sprintf(decimal_string, "%d", *h);
        char *temp = hash;
        hash = ccn_str_cat(hash, &decimal_string[0]);
        mem_free(temp);
        mem_free(h);
        h = array_pop(hashes);
    }
    if (h) mem_free(h);

    if (curr_hash == NULL)
        return hash;

    char *temp = hash;
    hash = ccn_str_cat(curr_hash, hash);
    mem_free(temp);
    mem_free(curr_hash);
    return hash;
}

typedef struct Info Info;
Info *hashAST_createinfo(void) {
    Info *info = mem_alloc(sizeof(Info));
    info->hashes = array_init(5);
    return info;
}
void hashAST_freeinfo(Info *info) {
    array_cleanup(info->hashes, mem_free);
    mem_free(info);
}
void hashAST_BinOp(BinOp *node, Info *info) {
    char *hash = NULL;
    trav_BinOp_left(node, info);
    hash = hash_array(info->hashes, hash);
    trav_BinOp_right(node, info);
    hash = hash_array(info->hashes, hash);

    char *val = u_int_to_str((unsigned int)node->op);
    hash = ccn_str_cat(hash, val);
    mem_free(val);
    unsigned int *h = hash_string(hash);
    array_append(info->hashes, h);
    mem_free(hash);
}

void hashAST_BoolConst(BoolConst *node, Info *info) {}
void hashAST_Cast(Cast *node, Info *info) {}
void hashAST_Decls(Decls *node, Info *info) {
    char *hash = NULL;
    trav_Decls_decl(node, info);
    hash = hash_array(info->hashes, hash);
    trav_Decls_next(node, info);
    hash = hash_array(info->hashes, hash);

    unsigned int val = imap_hash_fun(node);
    char *new = u_int_to_str(val);
    char *temp = hash;
    hash = ccn_str_cat(hash, new);
    mem_free(new);
    mem_free(temp);
    unsigned int *h = hash_string(hash);
    mem_free(hash);
    array_append(info->hashes, h);
}

void hashAST_DoWhile(DoWhile *node, Info *info) {}
void hashAST_ExprList(ExprList *node, Info *info) {
    trav_ExprList_expr(node, info);
    char *hash = hash_array(info->hashes, NULL);
    trav_ExprList_next(node, info);
    hash = hash_array(info->hashes, hash);

    unsigned int *h = hash_string(hash);
    array_append(info->hashes, h);
}
void hashAST_FloatConst(FloatConst *node, Info *info) {}
void hashAST_For(For *node, Info *info) {}
void hashAST_FunBody(FunBody *node, Info *info) {
    char *hash = NULL;
    trav_FunBody_vardec(node, info);
    hash = hash_array(info->hashes, hash);
    trav_FunBody_stmtlist(node, info);
    hash = hash_array(info->hashes, hash);
    unsigned int *h = hash_string(hash);
    array_append(info->hashes, h);
}
void hashAST_FunCall(FunCall *node, Info *info) {}
void hashAST_FunDef(FunDef *node, Info *info) {
    char *hash = NULL;
    trav_FunDef_funbody(node, info);
    hash = hash_array(info->hashes, hash);
    trav_FunDef_funheader(node, info);
    hash = hash_array(info->hashes, hash);
    trav_FunDef_next(node, info);
    hash = hash_array(info->hashes, hash);

    unsigned int *val = hash_string(hash);
    mem_free(hash);
    array_append(info->hashes, val);
}
void hashAST_FunHeader(FunHeader *node, Info *info) {
    unsigned int *h = hash_string(node->id);
    array_append(info->hashes, h);
}
void hashAST_FunSymbol(FunSymbol *node, Info *info) {}
void hashAST_GlobalDec(GlobalDec *node, Info *info) {}
void hashAST_GlobalDef(GlobalDef *node, Info *info) {}
void hashAST_IfElse(IfElse *node, Info *info) {}
void hashAST_IntConst(IntConst *node, Info *info) {}
void hashAST_LocalFunDef(LocalFunDef *node, Info *info) {}
void hashAST_MonOp(MonOp *node, Info *info) {
    char *hash = NULL;
    trav_MonOp_expr(node, info);
    hash = hash_array(info->hashes, hash);

    char *val = u_int_to_str((unsigned int)node->op);
    hash = ccn_str_cat(hash, val);
    mem_free(val);
    unsigned int *h = hash_string(hash);
    mem_free(hash);
    array_append(info->hashes, h);
}
void hashAST_Param(Param *node, Info *info) {}
void hashAST_Return(Return *node, Info *info) {}

void hashAST_Root(Root *node, Info *info) {
    char *hash = NULL;
    char *temp = NULL;
    trav_Root_decls(node, info);
    hash = hash_array(info->hashes, NULL);
    trav_Root_funsymbol(node, info);
    hash = hash_array(info->hashes, hash);
    trav_Root_symbol(node, info);
    hash = hash_array(info->hashes, hash);

    char decimal_string[33];
    unsigned int val = imap_hash_fun(node);
    sprintf(decimal_string, "%d", val);
    hash = ccn_str_cat(hash, &decimal_string[0]);
    unsigned int *new_hash = mem_alloc(sizeof(int));
    *new_hash = smap_hash_fun(hash);
    mem_free(hash);
}

void hashAST_StmtList(StmtList *node, Info *info) {
    char *hash = NULL;
    trav_StmtList_stmt(node, info);
    hash = hash_array(info->hashes, hash);
    trav_StmtList_next(node, info);
    hash = hash_array(info->hashes, hash);

    unsigned int val = imap_hash_fun(node);
    char *res = u_int_to_str(val);
    hash = ccn_str_cat(hash, res);
    mem_free(res);
    unsigned int *h = hash_string(hash);
    mem_free(hash);
    array_append(info->hashes, h);

}
void hashAST_Symbol(Symbol *node, Info *info) {}
void hashAST_Ternary(Ternary *node, Info *info) {}
void hashAST_Var(Var *node, Info *info) {
    unsigned int *h = hash_string(node->id);
    array_append(info->hashes, h);
}
void hashAST_VarDec(VarDec *node, Info *info) {
    char *hash = NULL;
    char *temp = NULL;
    trav_VarDec_expr(node, info);
    hash = hash_array(info->hashes, hash);
    trav_VarDec_next(node, info);
    hash = hash_array(info->hashes, hash);
    mem_free(temp);

    hash = ccn_str_cat(hash, node->id);
    int *hash_val = mem_alloc(sizeof(int));
    *hash_val = smap_hash_fun(hash);
    array_append(info->hashes, hash_val);
}
void hashAST_VarLet(VarLet *node, Info *info) {
    char *hash = NULL;
    trav_VarLet_expr(node, info);
    hash = hash_array(info->hashes, hash);
    char *temp = hash;
    hash = ccn_str_cat(hash, node->id);
    mem_free(temp);
    unsigned int *h = hash_string(hash);
    mem_free(hash);
    array_append(info->hashes, h);
}
void hashAST_While(While *node, Info *info) {}
