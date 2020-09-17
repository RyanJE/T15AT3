#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

char * numToDay(int n) {

	switch(n) {
		case 0: return "Sun";
		case 1: return "Mon";
		case 2: return "Tue";
		case 3: return "Wed";
		case 4: return "Thu";
		case 5: return "Fri";
		case 6: return "Sat";
		default: assert(0);
	}

}
int main(void) {
	printf("%s", numToDay(0));
}

char *numToDayR(int n)
{
	assert(0 <= n && n <= 6);
	char *day;
	if (n == 0) {
		day = "Sun";
	} else if (n == 1) {
		day = "Mon";
	} else if (n == 2) {
		day = "Tue";
	} else if (n == 3) {
		day = "Wed";
	} else if (n == 4) {
		day = "Thu";
	} else if (n == 5) {
		day = "Fri";
	} else if (n == 6) {
		day = "Sat";
	}
	return day;
}
