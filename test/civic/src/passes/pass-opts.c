#include <stdio.h>
#include "generated/ast.h"
#include "core/cycle.h"

static int notifies = 100;

Root *pass_Optimisation1_entry(Root *tree) {
    if (notifies > 0) {
        ccn_cycle_notify();
        notifies--;
    }
    printf("Opt1\n");

    return tree;
}
Root *pass_Optimisation2_entry(Root *tree) {
    printf("Opt2\n");

    return tree;
}

Root *pass_Optimisation3_entry(Root *tree) {
    printf("Opt3\n");

    return tree;
}
static int bla = 1;
FunDef *pass_Optimisation1_entry_FunDef(FunDef *tree) {
	if (bla > 0) {
	   ccn_cycle_notify();
	   bla--;
	}
	printf("FUNDEF: %p\n", tree);
	return tree;
}

FunDef *pass_Optimisation2_entry_FunDef(FunDef *tree) {
	return tree;
}

FunDef *pass_Optimisation3_entry_FunDef(FunDef *tree) {
	return tree;
}
