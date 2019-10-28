The DSL Syntax
==========================


================
Enum
================
An enum in the DSL maps to an enum in C. It can be used to add extra type information to a node.
It always requires a prefix that needs to be identical and should not collide with prefixes owned by *CoCoNut*.
In the values block, the values of the enum can be written. These will map to the values in the C enum and the order
used is kept. Every value will be prefixed with the prefix and to every enum a *NULL* value will be added.

.. code-block:: text

    enum <name> {
        prefix = <identifier>,
        values {
            <value 1>, <value 2>, ...
        }
    }

An example enum definition looks as follows:

.. code-block:: text

    enum binop {
        prefix = BO,
        values {
            add, sub, mul, div, rem
        }
    }


===============
Node
===============
A node can consist out of children and attributes. Children link to other nodes, which allows to build a tree.
Attributes is information stored in the node, every attribute has a type and a name. This then becomes a field in the C struct of the node.
In every DSL 'program' there must be one *root* node present. The *root* node will be the root in your AST.

.. code-block:: text

    [root] node <name> {
        [children {
            <child 1>,
            <child 2>
        },]
        [attributes {
            <attribute 1>,
            <attribute 2>
        }]
    }

An example node definition looks as follows:

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


==================
Nodeset
==================
Some nodes might have children that can be of multiple types. Therefore a nodeset can be created. The node then gets the nodeset
as a child and all the typesin the nodeset can then be used as a child. A nodeset requires a name and a set of nodes.
Nodes use a set expression, which allows to combined several nodesets to build new ones. The set of nodes should contain
defined nodes in the DSL.

.. code-block:: text

    nodeset <name> {
        nodes = <set expr>
    }


It is also possible to use a short notation for nodesets.
::

    nodeset <name> = <set expr>

A set expression is given by a combination of set operations, inline set definitions and references to defined nodesets.
The following set operations are supported:
::

    | Set union
    & Set intersect
    - Set difference

Combining the set operations with inline definitions and references, we can define a simple
Expr nodeset as follows:
::

    nodeset Expr = {Var, Cast} | Constant

While in the longer form it looks as follows:
::

    nodeset Expr {
        nodes = {Var, Cast} | Constant
    }

The {Var, Cast} statement is an inline set definition and the *Constant* is a reference to another defined nodeset. So, when an identifier is not
enclosed with {} it is seen as a reference to another nodeset. It is also possible to use () to group set expressions and define determination order.


===============
Pass
===============
Passes are the simplest form of an action that can be defined. A pass is simply a function that gets called.
A pass needs a name and a function name. The function name will map to the function name generated in the C code.
It is possible to define information in the info field and again a prefix.

.. code-block:: text

    pass <name> {
        [info = <string>,]
        [prefix = <identifier>,]
        func = <function name>
    }

An example of a pass looks as follows:

::

    pass ScanParse {
        info = "Scan and parse the source files and construct the AST.",
        prefix = SP,
        func = doScanParse
    }


It is also possible to define a pass using a shorter notation. With the shorter notation the
name of the pass will be the function name.

.. code-block:: text

    pass <name>



====================
Traversal
====================
A traversal needs to define the nodes to traverse. Besides that it can also define a info string and a prefix.
The nodes are in the form of a set expression again and can use defined nodesets as well.

.. code-block:: text

    traversal <name> {
        [info = <string>,]
        [prefix = <identifier>,]
        nodes = <set expression>
    }

An example of a traversal is as follows:

.. code-block:: text

    traversal RenameFor {
        prefix = RFOR,
        nodes = {For, VarLet, Var}
    }


There are also traversals that need to traverse all nodes, in such cases the *nodes* block can be left out.
Or a shorthand traversal can be used in the form:

.. code-block:: text

    traversal <name>



================
Phase
================
Phase are used to group actions together. Phases contain an actions body, which contains a list of action statements. Action can be
passes, traversals or other phases. Besides actions, phases can also define a gate function and a root. If the gate function is defined
it will be called before the phase is started. If the gate function return *false*, the phase is skipped. This can be usefull to implement
optional optimisations. By specifying a root node the full AST will be divided in sub-trees, with the specified root node as the root of these trees.
The actions in the phase will then be executed on the sub-trees. This is usefull in optimisations where optimisations can be run on a functions in isolations.
To create these sub-trees it is required that these nodes define a child named *next*. If no child named *next* is present, the node can not be a sub-root.
During actions that target a sub-tree, the *next* child is set to *NULL*. It is important to not set a value to the *next* child in these actions, because that
value will be overwritten with the original value that was pointed to.

The phase also accepts the info string and a prefix.


.. code-block:: text

    phase <name> {
        [info = <string>,]
        [prefix = <identifier>,]
        [root = <node identifier>,]
        [gate [= <function name>],]

        actions {
            <action 1>;
            <action 2>;
        }

    }

An example phase is as follows:

.. code-block:: text

    phase ConstantFolding {
        prefix = CF,
        root = Fundef,
        gate = isContantFoldingEnabled,

        actions {
            constantFoldOperators;
        }
    }