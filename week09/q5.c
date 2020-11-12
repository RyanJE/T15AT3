#include <stdio.h>
#include <stdlib.h>
char *arrayToStr(int a[], int n) {
    char *t = calloc(((2*n)+3), sizeof(char));
    t[0] = '[';
    for (int i = 0; i < n;++i) 
    sprintf(t + 1 + 2*i,(i == (n-1))?"%d":"%d,",a[i]);
    t[2*n] = ']';
    return t;
}

void mergeSort(int A[], int lo, int hi) {
    printf("Called mergeSort(%s,%d,%d)\n", 
        arrayToStr(A + lo,hi - lo + 1), lo, hi);
	if (lo >= hi) {
    printf("Immediately Exited function mergeSort(%s,%d,%d)\n", 
        arrayToStr(A + lo,hi - lo + 1), lo, hi);
    return;
    }
	
	int mid = (lo + hi) / 2;
	mergeSort(A, lo, mid);
	mergeSort(A, mid + 1, hi);
	merge(A, lo, mid, hi);
    printf("Exited function mergeSort(%s,%d,%d)\n", 
        arrayToStr(A + lo,hi - lo + 1), lo, hi);
}

void merge(int A[], int lo, int mid, int hi) {
    printf("Called merge\nMerging %s and %s\n", 
        arrayToStr(A + lo,mid - lo + 1),
        arrayToStr(A + mid + 1,hi - mid));
	int nitems = hi - lo + 1;
	int *tmp = malloc(nitems * sizeof(int));
	
	int i = lo;
	int j = mid + 1;
	int k = 0;
	
	// scan both segments into tmp
	while (i <= mid && j <= hi) {
		if (A[i] <= A[j]) {
			tmp[k++] = A[i++];
		} else {
			tmp[k++] = A[j++];
		}
	}
	
	// copy items from unfinished segment
	while (i <= mid) tmp[k++] = A[i++];
	while (j <= hi)  tmp[k++] = A[j++];
	
	// copy items from tmp back to main array
	for (i = lo, k = 0; i <= hi; i++, k++) {
		A[i] = tmp[k];
	}
	free(tmp);
}

int main(void) {
    int c[] = { 1, 4, 5, 6, 7, 2, 3, 4, 7, 9 };
    int d[] = { 9,8,7,6,5 };
    mergeSort(d,0,4);
}