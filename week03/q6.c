#include "tree.h"
#include<stdio.h>

/*
Base Case: t == NULL: return 0
Recursive Case:
(every other case)
return 1 + node(left) + node(right)

*/
int BSTreeNumNodes(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
    }
}

int main (void) {
    BSTree tree = newNode(3);
    tree->left = newNode(5);
    tree->left->left = newNode(4);
    tree->left->right = newNode(10);
    tree->right = newNode(7);
    printf("Expected value = 5\n");
    printf("Actual Value = %d\n", BSTreeNumNodes(tree));
}