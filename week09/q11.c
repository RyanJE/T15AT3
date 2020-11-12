#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXNAME 100
#define MAXSTUDENTS 100

typedef struct student {
	int  zid;            // 7-digit number
	char name[MAXNAME];  // names are stored *within* the struct
	int  prog;           // 4-digit number
	int  favnum;         // favourite number
} Student;
 
// return -ve if a < b, +ve if a > b, 0 if a == b
int stuCmp(const void *a, const void *b);
 
int main(int argc, char *argv[])
{
	Student students[MAXSTUDENTS];

	// read stdin line-by-line into students[]
	int i = 0;
	while (scanf("%d %s %d %d",
	             &students[i].zid, students[i].name,
	             &students[i].prog, &students[i].favnum) == 4)
	{
		i++;
	}

	// sort the students[] array
	int nstudents = i;
	qsort(students, nstudents, sizeof(Student), stuCmp);

	// print the contents of the students[] array
	for (i = 0; i < nstudents; i++) {
		printf("%7d %-20s %4d %d\n",
		       students[i].zid, students[i].name, students[i].prog,
		       students[i].favnum);
	}

}
