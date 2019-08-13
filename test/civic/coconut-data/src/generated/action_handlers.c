#include "generated/enum.h"
#include "generated/action_handlers.h"
#include "core/action_handling.h"
#include "generated/gate_functions.h"
#include "generated/trav-ast.h"
#include "core/internal_phase_functions.h"
#include "lib/memory.h"
#include "lib/str.h"
#include <stdbool.h>
ccn_action_t *get_ccn_action_from_id(enum ACTION_IDS);
#include "generated/pass-Optimisation1.h"
#include "generated/pass-Optimisation2.h"
#include "generated/pass-Optimisation3.h"
#include "generated/pass-ScanAndParse.h"
#include "generated/pass-Test.h"
static ccn_action_t action_array[CCN_NUM_OF_ACTIONS] = {{.type = action_NULL}};
enum ACTION_IDS CodeGen_ids_table[3] = {
ACTION_ID_ByteCode, ACTION_ID_Print, ACTION_ID_NULL
};
enum ACTION_IDS LoadProgram_ids_table[2] = {
ACTION_ID_ScanAndParse, ACTION_ID_NULL
};
enum ACTION_IDS Optimisations_ids_table[4] = {
ACTION_ID_Optimisation1, ACTION_ID_Optimisation2, ACTION_ID_Optimisation3, 
ACTION_ID_NULL
};
enum ACTION_IDS RootPhase_ids_table[5] = {
ACTION_ID_LoadProgram, ACTION_ID_SemanticAnalysis, ACTION_ID_Optimisations, 
ACTION_ID_CodeGen, ACTION_ID_NULL
};
enum ACTION_IDS SemanticAnalysis_ids_table[2] = {
ACTION_ID_ByteCode, ACTION_ID_NULL
};
ccn_action_t *get_ccn_action_from_id(enum ACTION_IDS id) {
    return &action_array[id];
}

ccn_action_t *make_trav_action(ccn_action_t *action, TraversalType trav_type, enum ACTION_IDS id, char *name) {
    ccn_traversal_t *trav = mem_alloc(sizeof(ccn_traversal_t));
    trav->trav_type = trav_type;
    action->type = action_traversal;
    action->traversal = trav;
    action->action_id = id;
    action->name = ccn_str_cpy(name);
    return action;
}

ccn_action_t *make_pass_action(ccn_action_t* action, void *(*func)(void*, NodeType), enum ACTION_IDS id, char *name) {
    ccn_pass_t *pass = mem_alloc(sizeof(ccn_pass_t));
    pass->func = func;
    action->type = action_pass;
    action->action_id = id;
    action->pass = pass;
    action->name = ccn_str_cpy(name);
    return action;
}

ccn_action_t *make_phase_action(ccn_action_t* action, enum ACTION_IDS id, enum ACTION_IDS *id_table, bool (*gate)(void), char *name, bool is_cycle) {
    ccn_phase_t *phase = mem_alloc(sizeof(ccn_phase_t));
    phase->gate_func = NULL;
    phase->action_types = id_table;
    phase->is_cycle = is_cycle;
    phase->action_id = id;
    phase->root_type = NT_Root;
    action->type = action_phase;
    action->action_id = id;
    action->phase = phase;
    action->name = ccn_str_cpy(name);
    return action;
}

void init_action_array() {
    make_trav_action(&action_array[ACTION_ID_ByteCode], TRAV_ByteCode, ACTION_ID_ByteCode, "ByteCode");
    make_trav_action(&action_array[ACTION_ID_Context], TRAV_Context, ACTION_ID_Context, "Context");
    make_trav_action(&action_array[ACTION_ID_Print], TRAV_Print, ACTION_ID_Print, "Print");
    make_trav_action(&action_array[ACTION_ID_Refactor], TRAV_Refactor, ACTION_ID_Refactor, "Refactor");
    make_trav_action(&action_array[ACTION_ID_RenameFor], TRAV_RenameFor, ACTION_ID_RenameFor, "RenameFor");
    make_trav_action(&action_array[ACTION_ID_SplitInit], TRAV_SplitInit, ACTION_ID_SplitInit, "SplitInit");
    make_trav_action(&action_array[ACTION_ID_Symbols], TRAV_Symbols, ACTION_ID_Symbols, "Symbols");
    make_trav_action(&action_array[ACTION_ID_TypeCheck], TRAV_TypeCheck, ACTION_ID_TypeCheck, "TypeCheck");
    make_pass_action(&action_array[ACTION_ID_Optimisation1], &dispatch_pass_Optimisation1, ACTION_ID_Optimisation1, "Optimisation1");
    make_pass_action(&action_array[ACTION_ID_Optimisation2], &dispatch_pass_Optimisation2, ACTION_ID_Optimisation2, "Optimisation2");
    make_pass_action(&action_array[ACTION_ID_Optimisation3], &dispatch_pass_Optimisation3, ACTION_ID_Optimisation3, "Optimisation3");
    make_pass_action(&action_array[ACTION_ID_ScanAndParse], &dispatch_pass_ScanAndParse, ACTION_ID_ScanAndParse, "ScanAndParse");
    make_pass_action(&action_array[ACTION_ID_Test], &dispatch_pass_Test, ACTION_ID_Test, "Test");
    make_phase_action(&action_array[ACTION_ID_CodeGen], ACTION_ID_CodeGen, CodeGen_ids_table, NULL, "CodeGen", false);
    make_phase_action(&action_array[ACTION_ID_LoadProgram], ACTION_ID_LoadProgram, LoadProgram_ids_table, NULL, "LoadProgram", false);
    make_phase_action(&action_array[ACTION_ID_Optimisations], ACTION_ID_Optimisations, Optimisations_ids_table, Optimisations_gate, "Optimisations", true);
    make_phase_action(&action_array[ACTION_ID_RootPhase], ACTION_ID_RootPhase, RootPhase_ids_table, NULL, "RootPhase", false);
    make_phase_action(&action_array[ACTION_ID_SemanticAnalysis], ACTION_ID_SemanticAnalysis, SemanticAnalysis_ids_table, NULL, "SemanticAnalysis", false);
    action_array[ACTION_ID_NULL].type = action_NULL;
}

void dispatch_traversals(NodeType type, void *node, TraversalType trav_type) {
    switch (type) {
    case NT_BinOp:
        trav_start_BinOp(node, trav_type);
        break;
    case NT_BoolConst:
        trav_start_BoolConst(node, trav_type);
        break;
    case NT_Cast:
        trav_start_Cast(node, trav_type);
        break;
    case NT_Decls:
        trav_start_Decls(node, trav_type);
        break;
    case NT_DoWhile:
        trav_start_DoWhile(node, trav_type);
        break;
    case NT_ExprList:
        trav_start_ExprList(node, trav_type);
        break;
    case NT_FloatConst:
        trav_start_FloatConst(node, trav_type);
        break;
    case NT_For:
        trav_start_For(node, trav_type);
        break;
    case NT_FunBody:
        trav_start_FunBody(node, trav_type);
        break;
    case NT_FunCall:
        trav_start_FunCall(node, trav_type);
        break;
    case NT_FunDef:
        trav_start_FunDef(node, trav_type);
        break;
    case NT_FunHeader:
        trav_start_FunHeader(node, trav_type);
        break;
    case NT_FunSymbol:
        trav_start_FunSymbol(node, trav_type);
        break;
    case NT_GlobalDec:
        trav_start_GlobalDec(node, trav_type);
        break;
    case NT_GlobalDef:
        trav_start_GlobalDef(node, trav_type);
        break;
    case NT_IfElse:
        trav_start_IfElse(node, trav_type);
        break;
    case NT_IntConst:
        trav_start_IntConst(node, trav_type);
        break;
    case NT_LocalFunDef:
        trav_start_LocalFunDef(node, trav_type);
        break;
    case NT_MonOp:
        trav_start_MonOp(node, trav_type);
        break;
    case NT_Param:
        trav_start_Param(node, trav_type);
        break;
    case NT_Return:
        trav_start_Return(node, trav_type);
        break;
    case NT_Root:
        trav_start_Root(node, trav_type);
        break;
    case NT_StmtList:
        trav_start_StmtList(node, trav_type);
        break;
    case NT_Symbol:
        trav_start_Symbol(node, trav_type);
        break;
    case NT_Ternary:
        trav_start_Ternary(node, trav_type);
        break;
    case NT_Var:
        trav_start_Var(node, trav_type);
        break;
    case NT_VarDec:
        trav_start_VarDec(node, trav_type);
        break;
    case NT_VarLet:
        trav_start_VarLet(node, trav_type);
        break;
    case NT_While:
        trav_start_While(node, trav_type);
        break;
    default:
        break;
    }
}

void *dispatch_pass_Optimisation1(void *node, NodeType root) {
    switch (root) {
    case NT_Root:
        return pass_Optimisation1_entry(node);
    default:
        return node;
    }
}

void *dispatch_pass_Optimisation2(void *node, NodeType root) {
    switch (root) {
    case NT_Root:
        return pass_Optimisation2_entry(node);
    default:
        return node;
    }
}

void *dispatch_pass_Optimisation3(void *node, NodeType root) {
    switch (root) {
    case NT_Root:
        return pass_Optimisation3_entry(node);
    default:
        return node;
    }
}

void *dispatch_pass_ScanAndParse(void *node, NodeType root) {
    switch (root) {
    case NT_Root:
        return pass_ScanAndParse_entry(node);
    default:
        return node;
    }
}

void *dispatch_pass_Test(void *node, NodeType root) {
    switch (root) {
    case NT_Root:
        return pass_Test_entry(node);
    default:
        return node;
    }
}

TraversalType get_sub_root_find_traversals(NodeType from, NodeType to) {
    return TRAV_NULL;
}

size_t get_offset_next(NodeType type) {
    return 0;
}

void ccn_destroy_action(ccn_action_t *action) {
    mem_free(action->name);
    if (action->type == action_traversal) {
        mem_free(action->traversal);
    }

    if (action->type == action_pass) {
        mem_free(action->pass);
    }

    if (action->type == action_phase) {
        mem_free(action->phase);
    }

}

void ccn_destroy_action_array() {
    if (action_array[0].type == action_NULL) return;
    size_t index = 0;
    ccn_action_t *action = &action_array[index++];
    while (action->type != action_NULL) {
        ccn_destroy_action(action);
        action = &action_array[index++];
    }
    action_array[0].type = action_NULL;
}


