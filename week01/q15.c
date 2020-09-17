#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;
 
typedef Node* List;  // pointer to first Node

/*
Iterative version: While loop
*/
int sumList(List l) {
	int sum = 0;
	List r = l;
	while(r != NULL) {
		sum += r->value;
		r = r->next;
	}
	return sum;
}

/*
Iterative version: For loop
*/
int sumListF(List l) {
	int sum = 0;
	for(List r = l;r != NULL;r = r->next) {
		sum += r->value;
		
	}
	return sum;
}
/*
for(a;b;c) {
	code
}
a;
while(b) {
	code
	c;
}
*/

/*
Recursive version
*/
int sumListR(List l) {
	if (l == NULL) {
		return 0;
	} else {
		return l->value + sumListR(l->next);
	}
}
/*

List
5 -> 2 -> 10 -> NULL

to apply a recursive function to something it must consist of a number of smaller instances of itself
e.g. each List consists of a head, and a smaller sublist that we apply the same algorithm to
e.g. A tree consists of a node, and two children that are also smaller trees
*/

int main(void) {
	List l = malloc(sizeof(Node));
	l->value = 5;
	l->next = malloc(sizeof(Node));
	l->next->value = 2;
	l->next->next = malloc(sizeof(Node));
	l->next->next->value = 10;
	for (List r = l; r != NULL; r = r->next){
		printf("%d", r->value);
		if (r->next != NULL) {
			printf("->");
		}
	}
	printf("\n");
	printf("sumList(l) = %d\n", sumList(l));
	printf("sumListF(l) = %d\n", sumListF(l));
	printf("sumListR(l) = %d\n", sumListR(l));
	return 0;
}
