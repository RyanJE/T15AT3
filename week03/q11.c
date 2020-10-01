#include "tree.h"
#include<stdio.h>

/*
base case:
t == NULL: return 0
recursive case:
if t->value > val: explore 1 + left + right
if t->value <= val: go right
*/

int BSTreeCountGreater(BSTree t, int val) {
    if (t == NULL) {
        return 0;
    } else if (t->value > val) {
        return 1 + BSTreeCountGreater(t->left, val) + BSTreeCountGreater(t->right, val);
    } else {
        return BSTreeCountGreater(t->right,val);
    }
}

int main (void) {
    BSTree tree = newNode(3);
    tree->left = newNode(1);
    tree->left->left = newNode(-1);
    tree->left->right = newNode(0);
    tree->right = newNode(10);
    tree->left->left->left = newNode(-50);
    tree->left->left->left->left = newNode(-100);
    tree->left->left->left->left->left = newNode(-1456);
    printf("Number of nodes greater than 4 is 1, found %d\n", BSTreeCountGreater(tree, 4));
}