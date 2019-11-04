Quickstart
===============

A script in the CoCoNut directory called *setup.sh* will build cocogen and setup an artifacts directory.
The artifacts directory will contain all the stuff for the coconut static libary. By placing this in a separate
directory it can be easily removed and ignored.

So, execute the following command:

.. code-block:: bash

    $ ./lib/CoCoNut/setup.sh


Now, executing the $ tree -L 2 command in your shell should, excluding your own files, show the following structure:

.. code-block:: text

    .
    ├── CoCoNut-artifact
    │   ├── coconut_flags.mk
    │   ├── include
    │   ├── Makefile
    │   └── src
    ├── lib
        └── CoCoNut


The next step is creating your DSL file, it is now a good idea to read the tutorial.

After you have created the DSL file you need to generate the common structure in C code.
This is done by executing *cocogen*, the meta compiler of *CoCoNut*. The meta compiler
can be found in the *bin* directory of your the artifacts directory. If you followed the examples
this is under lib/CoCoNut. An example of executing the meta compiler with your DSL file named *main.coconut* is as follows:

.. code-block:: bash

    $ ./CoCoNut-artifact/bin/cocogen --header-dir CoCoNut-artifacts/include --source-dir CoCoNut-artifacts/src src/dsl/main.coconut

The meta compiler will automatically create a generated directory in your header and source directory and place all generated files there.
If the meta compiler did not signal any errors the *CoCoNut* library needs to be compiled.
Run the following command:

.. code-block:: bash

    $ make -C ./CoCoNut-artifacts

This will build the static library *coconutlib*, found in the *bin* directory of the artifacts directory.
To build your compiler it is required to link with the *coconutlib* library.

It is easiest to integrate these commands within your build system. We assume you use a simple Makefile in the following example. It can be ported
to other build systems.

Inside the artifacts directory a makefile is present with the required flags to link the *coconutlib* library. The makefile
is called *coconut_flags.mk*. The coconut_flags makefile adds the required parameters to the LDFLAGS and LDLIBS variables to link
with the library. It also defines some useful variables to use in your own makefile, which are displayed in the following table:

+----------------------+----------------------------------------------------------------------------------+
| Variable             | Purpose                                                                          |
+======================+==================================================================================+
| COCONUT_INCLUDE      | The include path required to be appended to your include variable or the CFLAGS. |
+----------------------+----------------------------------------------------------------------------------+
| COCONUT_HEADER_DIR   | The  location of the header directory in the CoCoNut-artifacts directory.        |
+----------------------+----------------------------------------------------------------------------------+
| COCONUT_SOURCE_DIR   | THe location of the source directory in the CoCoNut-artifacts directory.         |
+----------------------+----------------------------------------------------------------------------------+
| COCONUT_DIR          | The location of the CoCoNut-artifacts directory                                  |
+----------------------+----------------------------------------------------------------------------------+
| COCONUT_LIB          | The location of the static library required to link                              |
+----------------------+----------------------------------------------------------------------------------+

Utilising these variables we can construct the following rules for a very simple Makefile, that will rebuild
the static library when your DSL file updates.

.. code-block:: Makefile

    include CoCoNut-artifacts/coconut_flags.mk

    INCLUDE_FlAGS += $(COCONUT_INCLUDE)
    CFLAGS = -std=gnu11

    MAIN_DSL := src/dsl/main.coconut

    $(COCONUT_LIB): $(MAIN_DSL)
        ./$(COCONUT_DIR)/bin/cocogen --header-dir $(COCONUT_HEADER_DIR) --source-dir $(COCONUT_SOURCE_DIR) $<
        make "CFLAGS=$(CFLAGS)" -C $(COCONUT_DIR)