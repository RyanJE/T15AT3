#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MAXLEN 100

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Incorrect number of arguments\n");
        exit(1);
    }
    FILE *f1 = fopen(argv[1],"r");
    FILE *f2 = fopen(argv[2],"r");
    if (f1 == NULL || f2 == NULL) {
        printf("Invalid input files.\n");
        exit(1);
    }
    char tmp1[MAXLEN];
    char tmp2[MAXLEN];
    char *t1 = fgets(tmp1, MAXLEN,f1);
    char *t2 = fgets(tmp2, MAXLEN,f2);
    while (t1 && t2) {
        if (strcmp(tmp1,tmp2) < 0) {
            printf("%s\n", tmp1);
            t1 = fgets(tmp1, MAXLEN,f1);
        } else {
            printf("%s\n", tmp2);
            t2 = fgets(tmp2, MAXLEN,f2);
        }
    }
    while (t1) {
        printf("%s\n",tmp1);
        t1 = fgets(tmp1, MAXLEN,f1);
    }
    while (t2) {
        printf("%s\n",tmp2);
        t2 = fgets(tmp2, MAXLEN,f2);
    }
    return 0;

    // Perform merge

}