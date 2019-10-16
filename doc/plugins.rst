Using plugins
=============

*CoCoNut* provides several plugins to ease the development process. The plugins can be activated with a flag
to *cocogen*, which then generates the code for the plugin. The plugins are designed in such a way that it does
not impose a compiler flag on your compiler, this does require to pass the command line arguments to the phase driver.

====================
Consistency checking
====================
Using the *--consistency-checks* flag with *cocogen* the code for consistency checking is generated for your compiler.
Consistency checking uses the lifetimes defined in the DSL file to check if the AST is still consistent according
to your specification. If the AST is incosistent an error will be displayed with the violation. Consistency checking
is meant for debugging your compiler.

=========
Profiling
=========
Using the *--profiling** flag with *cocogen*, the code to track time spent in phases and traversals and the memory
allocated and freed is generated. It is then possible to call the functions in the phase driver to display this
information after your compiler has finished. The phase driver defined the following functions to control this:

ccn_print_time_statistics(int n);
ccn_print_mem_statistics(int m);
ccn_print_statistics(int n, int m);

So the time for every traversal and phase is tracked and the *n* determines the amount to print.
So using *n=10*, the top 10 time traversals and top 10 time phases are being printent. With the phase and traversal
that take longest being number 1. By setting *n=-1* all the phases and traversals are printed.
This is the same for the memory statistics.


============
Break points
============
Using the *--breakpoints** flag with *cocogen*, your compiler will contain the code for setting breakpoints during compilation.
A breakpoint will stop at a certain stage in the compiler, print the AST at that stage, and exit the compilation.
Breakpoints still need to be extracted by your own compiler parameters and given to the phase driver using
the: *ccn\_set\_breakpoint(char *)* function.