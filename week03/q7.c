#include "tree.h"
#include<stdio.h>
/*
base case: t == NULL: return 0
recursive case:
if value is even: return odd(left) + odd(right)
else if value is odd return 1 + odd(left) + odd(right)

*/
int BSTreeCountOdds(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->value % 2 == 1) {
        return 1 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
    } else {
        return 0 + BSTreeCountOdds(t->left) + BSTreeCountOdds(t->right);
    }
}

int main (void) {
    BSTree tree = newNode(3);
    tree->left = newNode(5);
    tree->left->left = newNode(4);
    tree->left->right = newNode(10);
    tree->right = newNode(7);
    printf("Expected value = 3\n");
    printf("Actual Value = %d\n", BSTreeCountOdds(tree));
}