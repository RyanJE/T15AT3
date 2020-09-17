#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
int main(int argc, char *argv[])
{
	int i, j, *a;
	int N = 0;
 
	// initialisation
	if (argc > 1) {
		fprintf(stderr, "Required 1 or more integer arguments to program");
		exit(-1);
		
	}
	assert(argc > 1);

	// argv[1] = "1234";
	//sscanf(argv[1], "%d", &N);
	N = atoi(argv[1]);

	assert(N > 0);
	
	a = malloc(N*sizeof(int));
	assert(a != NULL);
	for (i = 2; i < N; i++) a[i] = 1;
 
	// computation
	for (i = 2; i < N; i++) {
		if (a[i]) {
			for (j = i; i*j < N; j++) a[i*j] = 0;
		}
	}
 
	// results
	for (i = 2; i < N; i++) {
		if (a[i]) printf("%d\n",i);
	}
	return EXIT_SUCCESS;
}

/*
a. There are no braces around the bodies of some for loops. Why?
b. What is the line of code sccanf(argv[1], "%d", &N) doing?
c. Suggest a better alternative for sscanf
d. For each of the asserts
	- Describe the error being checked
	- Suggest a better error message
e. What are the values of a[0] and a[1]. Does it matter what the values are?
f. What si the purpose of this program?
*/
/*

...
0x100 (allocated bytes 0x100, 0x101, 0x102, 0x103)
0x104 <-
0x108
...

malloc(4) == 0x100

*/

