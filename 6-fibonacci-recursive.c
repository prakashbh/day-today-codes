#include <stdio.h>

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return(fibo(n - 1) + fibo(n - 2));
}


int main()
{
    int n;
    int result;
    printf("Enter the required nth number in fibonacci series: ");
    scanf("%d", &n);
    
    result = fibo(n);
    printf("The %d number in fibonacci series is %d\n", n, result);
    
    return 0;
}
