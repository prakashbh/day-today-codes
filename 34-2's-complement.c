#include <stdio.h>

int main()
{
    int num = 7;

    /// Two ways to get two's complement
    printf("%d\n", -num);
    printf("%d\n", ~num + 1);
    return 0;
}
