#include <stdio.h>
#include <stdlib.h>

/*
Letter    ASCII     Binary
---------------------------
a          97       1100001
A          65       1000001 
There is a difference of 32. We AND it with ~32 to convert the case
*/

int main()
{
    char c = 'a';
    int x = 32;
    c = c & ~32;
    printf("%c\n", c);
}
