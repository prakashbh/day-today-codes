#include <stdio.h>

int main()
{
    int n = 11;
    int result = n & 1;
    if(result)
        printf("Odd number\n");
    else
        printf("Even number\n");

    return 0;
}
