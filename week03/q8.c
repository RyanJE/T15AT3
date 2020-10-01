#include "tree.h"
#include<stdio.h>

/*
base case: 
no children: return 0
t == NULL: return -1

recursive case:
take height of ltree and rtree, return 1 + max(rtree,ltree)

*/

int BSTreeCountHeight(BSTree t) {
    if (t == NULL) {
        return -1;
    } else if (t->right == NULL && t->left == NULL) {
        return 0;
    } else {
        int rheight = BSTreeCountHeight(t->right);
        int lheight = BSTreeCountHeight(t->left);
        if (rheight > lheight) {
            return 1 + rheight;
        } else {
            return 1 + lheight;
        }
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
    printf("Expected value = 4\n");
    printf("Actual Value = %d\n", BSTreeCountHeight(tree));
}