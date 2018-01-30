#include <stdio.h>

void decimal_to_binary(int n)
{
    int bnum[50];
    int i = 0;
    int j;

    while (n > 0) {
         // Get and store the remainders
        bnum[i] = n % 2;
        
        n = n / 2;
        i++;
    }

    // Print in the reverse order
    for (j = i - 1; j >= 0; j--)
        printf("%d", bnum[j]);
}

int main()
{
    int n = 5;
    decimal_to_binary(n);
    return 0;
}
