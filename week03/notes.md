1.
Compiler flags

-E: Runs code through pre processer and returns results

```c
#include<stdio.h>

int main (void) {
    int t = 1;
}
```
-c: Creates object file from compilation
-o: o specifies output file name
-g: Includes debugger flags (used by gdb and others)
-O3: Runs optimiser on code, o3 is highest optimisation. Do not use when we want to debug with gdb or similar programs

2.
Makefiles consist of a target binary at the top, followed by a series of object files to create. Make starts at the recipe for the binary and goes through its component object files. For each object file, it checks whether it doesn't exists or if it already exists but is older than the most recent update times of *.c and *.h files. If these conditions are true, then the object file is recompiled. Once all components *.o files are created, the binary is compiled.

3.
Header Guard:
Esnure that the contents of .h isnt expanded by preprocesser more than once.

#ifndef X_H
#define X_H
// ... rest of X.h file ...
#endif

4.

BST values in left subtree always smaller than root,
values in right subtree always larger than root

5.

L = explore left subtree
V = Print node value
R = explore right subtree

Infix: L->V->R

Prefix: V->L->R

Postfix: L->R->V

Level: Explore nodes by their depth, left to right

Tree where infix == prefix 

1
 \
  2
   \
    3
     \
      4
       \
        5

Degenerate Tree == Linked list
Same prefix and infix

Output orders all same:
    - Tree with 1 node
    - Tree with 0 nodes

