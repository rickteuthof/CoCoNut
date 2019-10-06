# Installation
Working with the CoCoNut framework is easiest by adding CoCoNut as a submodule, which is achieved by running the following two commands in your shell.
```shell
$ git submodule add -b master https://github.com/leegbestand/CoCoNut.git lib/CoCoNut
$ git submodule update --init --recursive
```
These commands will place the CoCoNut dependency under the lib directory and initialise and update CoCoNut. 
It is then required to setup a directory in which your generated files will be placed and we need to compile *cocogen*, which is the metacompiler of CoCoNut. We have provided a setup script which can be found in the CoCoNut submodule. Assuming the submodule is placed under lib/CoCoNut the following command should be run.
```shell
$ ./lib/CoCoNut/setup.sh
```

