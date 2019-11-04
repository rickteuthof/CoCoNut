Tutorial
===================

In this tutorial, we will build a very simple line calculator using the CoCoNut framework.
Start by setting up the project using the steps outlined
in the getting started documentation.

This tutorial assumes you use the default locations used in the *setup* script.

The calculator supports five simple arithmetic operations and uses a simple line to parse and evaluate.
We will use *bison* and *flex* to parse the commands. This seems overkill but is just to
demonstrate how to integrate *bison* and *flex* with *CoCoNut*.


=============
Node creation
=============

The expressions will support binary arithmetic operations and integers.
Therefore we need to create two nodes, one will store the integers and the
other the binary operation.

We start with the node storing the number.

Open the *main.coconut* file, found in the src/dsl directory
and add the following code:

.. code-block:: text

    node Num {
        attributes {
            int value { constructor }
        }
    };

This will define a node, named *Num*, and the node has one attribute. For every node
definition, a struct is made, with the fields of the struct corresponding to the attributes
of the node. *CoCoNut* generates the constructor functions for your nodes based on the node definition.
To decide which attributes in a node need to be present in the constructor, the *constructor* keyword
should be used for attributes that require to be in the constructor.
Every node will have its file, in the artifacts directory under *include/generated/create\_%s*,
where the '%s' should be the name of the node.

We support five arithmetic operations, therefore we need to create an enum to store the operations.
Place the following code to create an enum in the dsl file

.. code-block:: text

    enum BinOpEnum {
        prefix = BO,
        values {
            mul, add, sub, div, rem
        }
    };

An enum always requires a prefix, to create a type of namespace. Enums in the *CoCoNut* dsl map to enums in C, with
one exception, *cocogen* will add a 'NULL' value as the last entry in the C enum. The 'NULL' enum can be used to disable
an enum.

Now that we have the Enum and can assign operations we can create the node for the binary operation.
Place the following code in your dsl file:

.. code-block:: text

    root node BinOp {
        children {
            Num left {constructor, mandatory},
            Num right {constructor, mandatory}
        },
        attributes {
            BinOpEnum op {constructor, mandatory}
        }
    };

This defines a node named BinOp. This node will be the root node. Every *CoCoNut* dsl translation unit should have one root node. This will directly
map to the root of your AST. The BinOp node contains an attribute, which holds a value of our previous defined enumeration. Also, two children are defined.
Children reference other nodes and will map to pointers to the defined structs in C. The children in the BinOp node are references to the Num node. After the type,
we give the children a name. We give the 'left' and 'right' name. The names will correspond to the fields in the structure in C. Besides using the constructor value in the
body of the children and attributes, the mandatory keyword is used as well. The mandatory keyword states that the child or attribute must be present in the node, so can not be 'NULL'.
The usage of this is further explained in ....

However, our current BinOp node can only contain numbers, so chained binary operations are impossible.
To support longer arithmetic expressions our binary operation should have multiple types as a possible child.
Therefore a nodeset is created. Copy the following code to your dsl file.

.. code-block:: text

    nodeset Expr = {BinOp, Num};

This defines a nodeset named Expr that can hold the BinOp and Num node. The type of child
can be a nodeset, which means it can contain all the node types in the nodeset.
So, we can rewrite our BinOp node in the following way:

.. code-block:: text

    root node BinOp {
        children {
            Expr left { constructor, mandatory},
            Expr right { constructor, mandatory }
        },
        attributes {
            BinOpEnum op { constructor, mandatory }
        }
    };

The children of type Num now have the 'Expr' type. Thus we can create chained binary operations because BinOp is a member in the Expr set.

All nodes in our AST have been created so we can work on the evaluation part of our calculator.

====================
The compilation flow
====================

Every *CoCoNut* translation unit requires a starting phase. A phase is a part of the structure of your compilation process.
Phases itself contains other phases, traversals or passes, denoted as actions.

.. code-block:: text

    start phase Evaluate {
        prefix = EV,

        actions {
            traversal printAST;
        }
    };

This defines a phase named Evaluate.
Phases can be used to divide the several stages of the compiler in a logical structure.
Our defined phase contains one action, a traversal. The traversal does not define which nodes to traverse. This means that it will
traverse all the defined nodes. Actions can be defined in the action's body of a phase, but also outside the phase and referenced in the phase.
That would look as follows:

.. code-block:: text

    traversal printAST;

    start phase Evaluate {
        prefix = EV,

        actions {
            printAST;
        }
    };


Now from the root of your project run *make*. If everything went correctly the *libcoconutlib.a* file
should be present in the CoCoNut-artifacts/bin directory.

*CoCoNut* generated all the constructors and structures for the defined nodes, nodesets and enums. We only
have to integrate this with our tool of choice, in this case, *bison* and *flex*.
We will not give a tutorial on *flex* and *bison* and both files can be found here:

To reference your AST inside the *bison* file you need include the create functions from CoCoNut.
Every node has its own create file, found in the generated directory inside your artifacts directory.
However, including the 'generated/create-ast.h' file includes all the create file automatically. So by placing:
'#include "generated/create-ast.h" in your *bison* file you can call all constructors.

A very simple setup for our compiler in *bison* looks as follows:

.. code-block:: text

    root: binop { parseresult = $$; }

    num: NUMBER { $$ = create_Num($1); }
    ;


    expr: binop { $$ = create_Expr_BinOp($1); }
        | num { $$ = create_Expr_Num($1); }
        ;

    binop: expr '+' expr { $$ = create_BinOp($1, $3, BO_add); }
        | expr '-' expr {$$ = create_BinOp($1, $3, BO_sub); }
        | expr '*' expr {$$ = create_BinOp($1, $3, BO_mul); }
        | expr '/' expr {$$ = create_BinOp($1, $3, BO_div); }
        | expr '%' expr {$$ = create_BinOp($1, $3, BO_rem); }
        ;


Now we need to create our main function and start the *CoCoNut* routine.
Create a C file and place the following code in it:


.. code-block:: C

    #include "generated/ast.h"
    #include "core/phase_driver.h"

    char *line_to_parse = "4 + (3 + 2)";

    int main() {
        ccn_phase_driver_init();
        ccn_phase_driver_start();
        ccn_phase_driver_destroy();
    }

All these functions are defined in the 'phase_driver.h' header.
The *init* function initialises the phase driver, after this step some variables can be set.
The *start* function starts the start phase. After the start function is called the destroy function
should be called to do some cleanup. After the start function, some other reporting functions can be called
to print performance information about your compiler. In the next pages, more information on this is given.

When you compile this with the setup defined in the *getting started* page, you will get compiler warnings.
The functions declarations that *cocogen* generates are not defined yet.
So let us do that now.

We have defined the pass 'scanparse' and the traversal 'printAST' in the DSL. *cocogen* generated the declarations of these function, we
now need to define them in the C language.
The 'scanparse' function will use the previous defined *bison* definition, so let us place it in the '.y' file.
Place the following code in the lowest section of a *bison* file.


.. code-block:: C

    BinOp *scanparse(Binop *root) {
        YY_BUFFER_STATE state = yy_scan_string(line_to_parse);
        yyparse();
        yy_delete_buffer(state);
        return parseresult;
    }

The *CoCoNut* runtime will call this function. The 'line_to_parse' variable is a global variable set in the main file
and contains the expression.

We also need to define the traversal, create a file for the traversal and place the following code in that file:

.. code-block:: C

    #include "generated/traversal-printAST.h"

    #include <stddef.h>
    #include <stdio.h>

    #include "lib/memory.h"

    typedef struct Info {
        int indent;

    } Info;

    Info *printAST_createinfo(void) {
        Info *info = mem_alloc(sizeof(Info));
        info->indent = 0;
        return info;
    }

    void printAST_freeinfo(Info *info) {
        mem_free(info);
        putchar('\n');
    }

    void printAST_BinOp(BinOp *node, Info *info) {
        putchar('(');
        trav_BinOp_left(node, info);
        putchar(' ');
        switch(node->op) {
        case BO_add:
            putchar('+');
            break;
        case BO_sub:
            putchar('-');
            break;
        case BO_mul:
            putchar('*');
            break;
        default:
            break;
        }
        putchar(' ');
        trav_BinOp_right(node, info);
        putchar(')');
    }

    void printAST_Num(Num *node, Info *info) {
        printf("%d", node->value);
    }


This prints our AST. It shows the basic of writing your traversal. Every traversal requires a
*create* and *free* info function. It is also required to define the Info struct in the source file of the traversal.
The example shows how to traverse the children, this is done by using the trav\_TYPE\_CHILDNAME function and then pass
the node and info struct to that function.

Now it is possible to compile everything together and run the program, which should print the [CCN] information
about your structure and the original expression.