#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct node * Node;
struct node {
    int value;
    Node next;
};
/*
    struct node takes up 8 Bytes: 
        4 bytes for int + 4 bytes for Node

    n:
    0
    0
    0
    0 value

*/

Node createNode(int value) {
    Node n = malloc(sizeof(struct node));
    assert(n != NULL);

    n->value = value;
    n->next = NULL;
    return n;
}

int main(void) {
    Node n1 = createNode(3);
    n1->next = createNode(1);
    n1->next->next = createNode(4);
    printf("%d -> %d -> %d -> X\n", n1->value, n1->next->value, n1->next->next->value);
    // freeNode(n1->next->next);
    // freeNode(n1->next);
    // freeNode(n1);
}