#include <stdio.h>

int main()
{
    int n = 15;
    int bits = 0;

    while(n)
    {
        bits = bits + 1;
        n = n & n-1;
    }

    printf("The number of set bits are %d\n", bits);

    return 0;
}
