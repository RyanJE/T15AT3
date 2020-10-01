#include <stdlib.h>
typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

//Inline function in the .h file, don't do this in assignments!
BSTree newNode(int val) {
    BSTree n = malloc(sizeof(BSTNode));
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}