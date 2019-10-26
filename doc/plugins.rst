The phase driver and using plugins
==================================

To interact with *CoCoNut* from your compiler the phase driver should be used.
The phase driver provides an API to communicate with *CoCoNut*.

This was already shorly displayed in the getting started area in the main function.

The first step is to initialise the phase driver, this is done with the: *ccn_phase_driver_init()* function.
This function will allocate and setup all the required resources for the phase driver. The phase driver is a
singleton and therefore there can only be one phase driver in your compiler at a time.

After initialising the phase driver you can execute *commands* on it. One command, we saw earlier, is
the start command. The start command is executed with the: *ccn_phase_driver_start()* function.
This will start the compilation and execute the phases and traversals you described.

After everything is finished the phase driver needs to be destroyed, this can be done with the: *ccn_phase_driver_destroy()* function.

So, a simple main function that initialises the phase driver, starts the compilation and destroys the phase driver looks as follows:

.. code-block:: C

    #include "generated/ast.h"
    #include "core/phase_driver.h"

    int main() {
        ccn_phase_driver_init();
        ccn_phase_driver_start();
        ccn_phase_driver_destroy();
    }


Besides the start command *CoCoNut* offers commands that target plugins you can enable.
The plugins can be used to ease your development process during debugging or profiling.

The code for the plugins are not automatically generated, but need to be enabled with a flag
to the metacompiler *cocogen*. Executing *cocogen --plugins* will give you a list of all the
plugins and how they are enabled.

After enabling them you need to provide the required data to the phase driver. The plugins
are desinged in such a way that they do not imposy any flags on your compiler, therefore
you need to provide the required flags for your own compiler. These command line
arguments should then be past to the phase driver.

Below are all the plugins explained, how you enable them and the possible commands for the phase driver.


====================
Consistency checking
====================
Using the *--consistency-checks* flag with *cocogen* the code for consistency checking is generated for your compiler.
Consistency checking uses the lifetimes defined in the DSL file to check if the AST is still consistent according
to your specification. If the AST is incosistent an error will be displayed with the violation. Consistency checking
is meant for debugging your compiler. Consistency checking has no API in the phase driver as everything is constructed
from the definition in your DSL file.

=========
Profiling
=========
Using the *--profiling** flag with *cocogen*, the code to track time spent in phases and traversals and the memory
allocated and freed is generated. It is then possible to call the functions in the phase driver to display this
information after your compiler has finished. The phase driver defines the following functions to control this:

.. code-block:: C

    ccn_print_time_statistics(int n);
    ccn_print_mem_statistics(int m);
    ccn_print_statistics(int n, int m);

So the time for every traversal and phase is tracked and the *n* determines how many records to print.
So if you want to see the 10 slowest phases and traversals make *n=10*. If you want to see all records set *n=-1*.
The memory follows the same approach. If you want to show both you can use the print statistics functions, where the
first argument is for the amount of time records and the second for the amount of memory records.


============
Break points
============
Using the *--breakpoints** flag with *cocogen*, your compiler will contain the code for setting breakpoints during compilation.
A breakpoint will stop the compiler when reached, print the AST at that stage, and exit the compilation.
Breakpoints still need to be extracted by your own compiler parameters and given to the phase driver using
the: *ccn\_set\_breakpoint(char *)* function. The string given to this function has the following signature:
*

=================
Inspection points
=================
Inspection points do the same as breakpoints except they do not stop the compilation. Inspection points can
be enabled using the *--inspectpoints* flag with *cocogen*.