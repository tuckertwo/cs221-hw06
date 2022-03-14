# General Information
This is a basic binary tree library;
its functions and types are defined and documented in `tree.hh`.
This library was written by Julian Jacklin and Tucker R. Twomey.

# Compiling and Testing
The compilation process for this library is fairly standard;
just generate a Makefile using `cmake` or `ccmake` and proceed
from there.
```
$ ccmake .
$ make -j4 # if your machine has 4 CPU cores
$ ./test_tree
```
