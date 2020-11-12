COMP2521 Tute 09
====
Q1.
- Stability: Two equal items in the list/array maintain order post-sort
- Adaptability: Algorithm can detect when the input is sorted.
E.g. Adaptive bubble-sort
- Comparison-Based: Any sort that directly compares two items to sort

- Non-comparison based: no comparison of items e.g. radix sort.

Radix sort:
{13,12,55,22}

fn(x) = most significant digit n

{ {13,12}, 22, 55 }

{ 12,13, 22, 55 }

Q2.

SORT BY NAME ONLY

COMP1927	Jane	3970
COMP1927	John	3978
COMP1927	Pete	3978
MATH1231	John	3978
MATH1231	Adam	3970
PSYC1011	Adam	3970
PSYC1011	Jane	3970

a. Stable Sort output

MATH1231	Adam	3970
PSYC1011	Adam	3970
COMP1927	Jane	3970
PSYC1011	Jane	3970
COMP1927	John	3978
MATH1231	John	3978
COMP1927	Pete	3978

b. Unstable Sort output

MATH1231	Adam	3970
PSYC1011	Adam	3970
PSYC1011	Jane	3970
COMP1927	Jane	3970
MATH1231	John	3978
COMP1927	John	3978
COMP1927	Pete	3978

Q4.
```c
int a[] = {4, 3, 6, 8, 2};
```

for each of the following sorting algorithms:

- selection sort: 
4 in 1st pass
3 in 2nd
2 in 3rd
1 in 4th
last pass no comparisons
- adaptive bubble sort (ends when a pass makes no swaps)
16 comparisons
array where we require less comparisons:
a[] = {1,2,3,4,5}
- insertion sort


Q5.

Mergesort

Q6.

```c
int partition(int A[], int lo, int hi)
{
	int pivot = A[lo]; // pivot
	int l = lo + 1;
	int r = hi;
	while (l < r) {
		while (l < r && A[l] <= pivot) l++;
		while (l < r && A[r] >= pivot) r--;
		if (l == r) break;
		swap(A, l, r);
	}
	int m = A[l] <= pivot ? l : l - 1;
	swap(A, lo, m);
	return m;
}
```

How would this function partition the following arrays?
1. { 5, 3, 9, 6, 4, 2, 9, 8, 1, 7 }
Pivot: 5 l: 1, r: 10
- { 5, 3, 9, 6, 4, 2, 9, 8, 1, 7 }
Pivot: 5, l:2, r:9
- { 5, 3, 1, 6, 4, 2, 9, 8, 9, 7 }
Pivot: 5, l:3, r:7
- { 5, 3, 1, 8, 4, 2, 9, 6, 9, 7 }
Pivot: 5, l:3, r:6
- { 5, 3, 1, 2, 4, 9, 8, 6, 9, 7 }
Pivot: 5, l:4, r:4
- { 5, 3, 1, 2, 4, 9, 8, 6, 9, 7 }
Pivot: 5, final array
- { 4, 3, 1, 2, 5, 9, 8, 6, 9, 7 }

2. { 5, 9, 8, 7, 6, 0, 1, 2, 3, 4 }
3. { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
4. { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }



sorted 1-> 2 -> 3 -> 4 -> 5:



