#include "tree.h"
#include<stdio.h>
// Leaf node == node with both children as NULL
// Internal Node == all noon-leaf nodes
/*
Base case:
t == NULL: return 0
if t is a leaf: return 0
Recursive case:
t is an internal node: return 1 + internal(left) + internal(right)
*/
int BSTreeCountInternal(BSTree t) {
    if (t == NULL || (t->left == NULL && t->right == NULL)) {
        return 0;
    } else {
        return 1 + BSTreeCountInternal(t->left) + BSTreeCountInternal(t->right);
    }
}

int main (void) {
    BSTree tree = newNode(3);
    tree->left = newNode(5);
    tree->left->left = newNode(4);
    tree->left->right = newNode(10);
    tree->right = newNode(7);
    tree->left->left->left = newNode(60);
    tree->left->left->left->left = newNode(100);
    tree->left->left->left->left->left = newNode(1456);
    printf("Expected value = 5\n");
    printf("Actual Value = %d\n", BSTreeCountInternal(tree));
}