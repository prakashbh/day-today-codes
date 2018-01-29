#include <stdio.h>

int fibo(int n)
{
    int fib[n+1];
    int i;
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}


int main()
{
    int n;
    int result;
    printf("Enter the required nth number in fibonacci series: ");
    scanf("%d", &n);

    if (n == 0)
        result = 0;
    else
        result = fibo(n);
    printf("The %d number in fibonacci series is %d\n", n, result);

    return 0;
}
