#include <stdio.h>
int main()
{
    int n, revnum = 0, rem = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n != 0)
    {
        rem = n % 10;
        revnum = revnum *10 + rem;
        n = n / 10;
    }

    printf("Reversed Number = %d", revnum);
    return 0;
}
