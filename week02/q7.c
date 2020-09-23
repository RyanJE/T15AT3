#include<stdio.h>
#include<string.h>
int palindrome(char *s);

int main (int argc, char* argv[]) {
    if (argc == 2) {
        printf("%s\n", (palindrome(argv[1]))?"yes":"no");
    }
    return 0;
}

/*
    S string
    for every index up to n/2:
        ensure S[index] == S[length - 1 - index] 

*/

int palindrome(char *s) {
    int len = strlen(s);
    // O(n) complexity
    for (int i = 0; i < len/2; ++i) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}