#include <stdio.h>
#include <stdlib.h>

unsigned long int catalan(int n) {
    if (n <= 1)
        return 1;

    unsigned long int res = 0;
    int i;
    for (i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);

    return res;
}

int main()
{
    int i, n;
    printf("Enter n to generate catalan numbers:\n");
    scanf("%d", &n);
    for (i=0; i<n; i++)
        printf("%lld\n", catalan(i));
    return 0;
}
