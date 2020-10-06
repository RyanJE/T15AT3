#include<string.h>
int main(void) {
    // str1 == 0xff003254
    char *str1 = "hello";
    // str2 == 0xfd003274
    char *str2 = "world";
    /*
    strcmp:
        if strcmp == 0: str1 == str2
        if strcmp < 0: str1 < str2
        if strcmp > 0: str1 > str2

        "aaa" > "aab" > "bbb"
    */
    if (strcmp(str1, str2)) {
        printf("str1 is less than str2\n");
    } else {
        printf("str1 is not less than str2\n");
    }
}
