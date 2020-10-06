#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct node *Node;
struct node {
    char *word;
    Node next;
};
//Word is a pointer to a place on the stack
// ex: 0xff00dd33
Node createNode(char *word) {
    Node n = malloc(sizeof(struct node));
    assert(n != NULL);

    n->word = strdup(word);
    n->next = NULL;
    return n;
}
/*
initial call:
Buffer contains (word1)
n1->word = 0xff00dd33 (word1)

next call:
scanf overwrites buffer at 0xff00dd33
n1->word = 0xff00dd33 (word2)

*/

int main(void) {
    Node n1;
    //
    char buffer[100];
    scanf("%s", buffer);
    n1 = createNode(buffer);
    scanf("%s", buffer);
    n1->next = createNode(buffer);
    scanf("%s", buffer);
    n1->next->next = createNode(buffer);

    printf("%s -> %s -> %s -> X\n", n1->word, n1->next->word, n1->next->next->word);

}