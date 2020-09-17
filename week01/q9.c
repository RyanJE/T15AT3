#include<stdio.h>
#include<stdlib.h>

void isVowel(char ch) {
    assert(islower(ch));
    /*
    switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("vowel"); break;
	default:
		printf("consonant"); break;
    */
   /*
   if (ch == 'a' || ch == 'e' || ch == 'i' 
   || ch == 'o' || ch == 'u') {
       printf("vowel\n");
   } else {
       printf("consonant\n");
   }
   */
   (ch == 'a' || ch == 'e' || ch == 'i' 
   || ch == 'o' || ch == 'u') ? printf("vowel\n"); 
   : printf("consonant\n");

   int n = (condition) ? val1 : val2;

}
    
}
