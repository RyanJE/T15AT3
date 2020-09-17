#include<stdio.h>
int main(void) {
    int   x, y;
    char *c, *d, *e, *f;
    
    x = y = 2;
    c = d = "abc";
    e = "xyz"; 
    f = "xyz";
    
    x++;
    *c = 'A'; // Trying to change first character of immutable string, segfault
}

/*
 x     y    c     d     e     f
 2     2   "abc"<-    "xyz"  "xyz"
 3     2   "abc"<-    "xyz"  "xyz"





*/
















