#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, result;

    n = 8;
    result = n & (n-1);
    printf("%d\n", !result);

    n = 7;
    result = n & (n-1);
    printf("%d\n", !result);

}
