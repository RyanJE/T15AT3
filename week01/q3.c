#include<stdio.h>
int main(int argc, char** argv) {
    char ch;
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("(%d, %s)\n", i, argv[i]);
    }
    while ((ch = getchar()) != EOF ) {
        printf("%c",ch);
    }
    return 0;
}