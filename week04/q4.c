typedef struct BSTNode *BSTree;
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
}BSTNode;
//
int printHeightDiff(BSTree t) {
    if (t == NULL) {
        return -1;
    } else if (t->right == NULL && t->left == NULL) {
        printf("data: %d, diff: 0", t->value);
        return 0;
    } else {
        int lt = printHeightDiff(t->left);
        int rt = printHeightDiff(t->right);
        printf("data: %d, diff: %d", t->value, lt - rt);
        return 1 + (lt < rt ? rt : lt);
    }
}
#define NOT_HEIGHT_BALANCED -99

int isHeightBalanced(BSTree t) {
    if (t == NULL) {
        return -1;
    } else if (t->right == NULL && t->left == NULL) {
        return 0;
    } else {
        int lt = printHeightDiff(t->left);
        int rt = printHeightDiff(t->right);
        if (lt == NOT_HEIGHT_BALANCED || rt == NOT_HEIGHT_BALANCED) {
            return NOT_HEIGHT_BALANCED;
        }
        else if (abs(lt - rt) <= 1) {
            return 1 + (lt < rt ? rt : lt);
        } else {
            return NOT_HEIGHT_BALANCED;
        }
    }
}
/*
    4
   /  \
  3    5
 /      \
2        6
/        \
1         6


*/


BSTree newNode(int val) {
    BSTree n = malloc(sizeof(BSTNode));
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main (void) {
    BSTree t = newNode(5);
    t->left = newNode(3);
    t->right = newNode(7);
    t->right->left = newNode(6);
    printHeightDiff(t);
    return 0;
}