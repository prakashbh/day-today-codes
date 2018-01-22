#include <stdio.h>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    int a, b;
    int result = 0;

    printf("Enter 2 numbers\n");
    scanf("%d %d", &a, &b);
    result = gcd(a,b);
    printf("GCD(%d, %d) = %d\n", a, b, result);

    return 0;
}
