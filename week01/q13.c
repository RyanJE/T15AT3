#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swapA(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void swap(int *a, int i, int j) {
    a[i] = a[i] + a[j];
    a[j] = a[i] - a[j];
    a[i] = a[i] - a[j];
}


int main(void) {
    int size = 5;
    int* k = malloc(sizeof(int)*size);
    printf("Before swap.\n[");
    for(int i = 0; i < size; i++) {
        k[i] = rand()%100 - rand()%100;
        printf(" %d ", k[i]);
    }
    printf("]\n");
    swap(k, 0, 4);
    printf("After swap.\n[");
    for(int i = 0; i < size; i++) {
        printf(" %d ", k[i]);
    }
    printf("]\n");
}