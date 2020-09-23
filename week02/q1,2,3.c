#include<stdlib.h>
typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef Node *List;
// First week
int length(List L) {
    int len = 0;
    for (List l = L; l != NULL; l = l->next) {
        len++;
    }
    return len;
}
// First week
int lengthR(List L) {
    if (L == NULL) {
        return 0;
    } else {
        return 1 + lengthR(L->next);
    }
}

int listOdd(List L) {
    int odd = 0;
    for (List l = L; l != NULL; l = l->next) {
        if (l->data%2 != 0) {
            ++odd;
        }
    }
    return odd;
}


/*
Base case:
L == NULL: return 0;
Recursive case:
L->data%2 == 0: something
L->data%2 != 0: something
*/
int listOddR(List L) {
    if (L == NULL) {
        return 0;
    } else if (L->data%2 == 0) {
        return listOddR(L->next);
    } else //(L->data%2 != 0) 
    {
        return 1 + listOddR(l->next);
    }
}

// First Week
int listSorted(List L) {
    if (L == NULL) {
        return true;
    }
	for (List l = l; l->next != NULL; l = l->next) {
        if (l->data > l->next->data) {
            return false;
        }
    }
	return true; 
}


/*
Base cases:
L == NULL: return true
l->next == NULL: return true
Recursive cases:
l->data > l->next->data
(l->data <= l->next->data)
*/
int listSortedR(List l) {
    if (l == NULL || l->next == NULL) {
        return true;
    } else {
        if (l->data <= l->next->data) {
            return listSortedR(L-next);
        } else {
            return false;
        }
        // return (l->data <= l->next->data) && listSortedR(L-next);
    }
}

List reverseList(List l) {
    
}

