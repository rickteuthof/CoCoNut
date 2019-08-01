#include "generated/ast.h"
#include "generated/copy-ast.h"
#include "generated/create-ast.h"
#include "generated/free-Root.h"
#include "generated/trav-ast.h"
#include "generated/enum.h"
#include "core/internal_phase_functions.h"
#include "core/action_handling.h"
#include "generated/action_handlers.h"

//#include "generated/serialization-Root.h"
//#include "generated/traversal-_CCN_CHK.h"

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* void serialization_write_binfile_VarLet(VarLet *syntaxtree, FILE *fp); */
/* VarLet *serialization_read_binfile_VarLet(FILE *fp); */
/* void serialization_write_binfile_Root(Root *syntaxtree, FILE *fp); */
/* Root *serialization_read_binfile_Root(FILE *fp); */

/// export int main() {
///     int a1;
///     int a2;
///     int a3;
///     int a4;
///     a1 = scanInt();
///     a2 = scanInt();
///     a3 = a1 + a2;
///     a4 = a3;
///     return a4;
/// }

FunDef *make_fundef(char *name) {
    VarDec *vda1 = create_VarDec(NULL, NULL, strdup("a1"), BT_int);
    VarDec *vda2 = create_VarDec(NULL, NULL, strdup("a2"), BT_int);
    VarDec *vda3 = create_VarDec(NULL, NULL, strdup("a3"), BT_int);
    VarDec *vda4 = create_VarDec(NULL, NULL, strdup("a4"), BT_int);
    vda1->next = vda2;
    vda2->next = vda3;
    vda3->next = vda4;

    // STMTs
    FunCall *scanint = create_FunCall(NULL, strdup("scanInt"));
    FunCall *scanint2 = create_FunCall(NULL, strdup("scanInt"));
    BinOp *plus =
        create_BinOp(create_Expr_Var(create_Var(strdup("a1"))),
                     create_Expr_Var(create_Var(strdup("a2"))), BO_add);

    BinOp *plus2 = 
        create_BinOp(create_Expr_Var(create_Var(strdup("a3"))), create_Expr_Var(create_Var(strdup("a4"))), BO_add);    
    VarLet *a1 = create_VarLet(create_Expr_FunCall(scanint), strdup("a1"));
    VarLet *a2 = create_VarLet(create_Expr_FunCall(scanint2), strdup("a2"));
    VarLet *a3 = create_VarLet(create_Expr_BinOp(plus), strdup("a3"));
    VarLet *a5 = create_VarLet(create_Expr_BinOp(plus2), strdup("a5"));
    VarLet *a4 =
        create_VarLet(create_Expr_Var(create_Var(strdup("a3"))), strdup("a4"));
    Return *returna4 =
        create_Return(create_Expr_Var(create_Var(strdup("a4"))));

    StmtList *stmtla1 = create_StmtList(NULL, create_Stmt_VarLet(a1));
    StmtList *stmtla2 = create_StmtList(NULL, create_Stmt_VarLet(a2));
    StmtList *stmtla3 = create_StmtList(NULL, create_Stmt_VarLet(a3));
    StmtList *stmtla4 = create_StmtList(NULL, create_Stmt_VarLet(a4));
    StmtList *stmtla5 = create_StmtList(NULL, create_Stmt_VarLet(a5));
    StmtList *stmtreturn = create_StmtList(NULL, create_Stmt_Return(returna4));
    stmtla1->next = stmtla2;
    stmtla2->next = stmtla3;
    stmtla3->next = stmtla4;
    stmtla4->next = stmtla5;
    stmtla5->next = stmtreturn;
    
    //VarLet *a1 = create_VarLet(create_Expr_FunCall("scanint"), strdup("a1"));
    //StmtList *stmtla1 = create_StmtList(NULL, create_Stmt_VarLet(a1));
    FunHeader *header = create_FunHeader(NULL, strdup(name), BT_int);
    FunDef *mainfun =
        create_FunDef(create_FunBody(NULL, stmtla1, vda1),
                      header, NULL,
                      NULL, NULL, true, false);
    
    return mainfun;
}

FunDef *create_n_fundefs(int n) {
    FunDef *root = make_fundef("main");
    FunDef *next = root;

    for (int i = 0; i < n -1; i++) {
        next->next = make_fundef("fundef");
        next = next->next;
    }
    return root;
}

int main() {
    double total = 0.0;
    double start, end;
    const int amount_of_funcs = 2;
    const int nodes_per_func = 45;     
    const int total_nodes = amount_of_funcs * nodes_per_func;
    FunDef *mainfun = create_n_fundefs(amount_of_funcs);
    Root *program = create_Root(
        create_Decls(create_Decl_FunDef(mainfun), NULL), NULL, NULL);
    
    _initialize_phase_driver();
    //ccn_set_breakpoint("Optimisations");
    ccn_set_print_n(5);
    init_action_array();
    ccn_action_t *action = get_ccn_action_from_id(ACTION_ID_RootPhase);
    ccn_dispatch_action(action, NT_Root, program);
    free_Root_tree(program);

    phase_driver_destroy();
    return 0;
}
