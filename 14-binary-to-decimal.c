#include <stdio.h>

void binary_to_decimal(int n)
{
    int dnum = 0;
    int last = 0;

    // Set base to 2^0
    int base = 1;

    while(n)
    {
        last = n % 10;
        n = n/10;
        dnum += last*base;
        base = base*2;
    }

    printf("%d\n", dnum);
}

int main()
{
    int n = 101;
    binary_to_decimal(n);
    return 0;
}
