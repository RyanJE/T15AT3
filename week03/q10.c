#include "tree.h"
#include<stdio.h>

/*
Base case:
t == NULL: return -1
t->value == key: return 0;
Recursive case:
if t->value > key: recurse on left subtree
if t->value < key: recursive on right subtree
compare key to current node
*/

int BSTreeNodeDepth(BSTree t, int key) {
    int tmp;
    if (t == NULL) {
        return -1;
    } else if (t->value == key) {
        return 0;
    } else if (t->value < key) {
        tmp = BSTreeNodeDepth(t->left, key);
    } else if (t->value > key) {
        tmp = BSTreeNodeDepth(t->right, key);
    } 
    if(tmp == -1) {
        return -1;
    } else {
        return 1 + tmp;
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
    printf("Depth of 100 is 4, found %d\n", BSTreeNodeDepth(tree, 100));
}