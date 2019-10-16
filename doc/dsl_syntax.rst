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


===============
Node
===============
A node can consist out of children and attributes. Children link to other nodes, which allows to build a tree.
Attributes is information stored in the node. In every DSL 'program' there must be one *root* node present.
The *root* node will be the root in your AST.

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

==================
Nodeset
==================
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

    nodeset Expr = {Var} | Constant

Where the '{}' denotes an inline nodeset and *Constant* is a reference to another defined nodeset.

====================
Traversal
====================
.. code-block:: text

    traversal <name> {
        [info = <string>,]
        [prefix = <identifier>,]
        nodes = <set expression>
    }

===============
Pass
===============
.. code-block:: text

    pass <name> {
        [info = <string>,]
        [prefix = <identifier>,]
        func = <function name>
    }

It is also possible to define a pass using a shorter notation. With the shorter notation the
name of the pass will be the function name.

.. code-block:: text

    pass <name>

================
Phase
================
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