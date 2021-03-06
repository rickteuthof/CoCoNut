Prefixes
========

.. highlight:: c

In AST framework provides a couple of enums and functions. All these functions
rely on prefixes, which cannot be used by the user in the ast file.

Reserved identifiers for enums are:

* NodeType
* TraversalType
* push
* pop
* current
* start
* createinfo
* freeinfo

Reserved prefixes which are used in functions and enums are:

* `NS_`

  Nodeset enum prefix.

* `NT_`

  Node type prefix.

* `TRAV_`

  Traversal type prefix.

* `create_`

  Prefix of the create functions to construct AST.

* `free_`

  Prefix of the free functions to free AST.

* `trav_`

  Prefix of the traversal functions to traverse children of nodes in the AST.

* `trav_start_`

  Prefix of the traversal functions to start a new traversal.

* `copy_`

  Prefix of the traversal functions to copy subtrees of the AST.

* `replace_`

  Prefix of the function to replace the current node.

* `traversal_`

  Prefix of the user defined traversal functions.

* `pass_`

  Prefix of the user defined pass functions.

* `phasedriver_`

  Prefix of phasedriver functions.

* `ccn_`

  All exported functions related to *CoCoNut*.

* `phase_`
  Functions and data related to per-phase information.