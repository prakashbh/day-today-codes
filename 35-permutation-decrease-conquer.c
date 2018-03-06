/*

Uses the definition of n! to generate the permutations.

Idea:
-----
Remove each item from the given n items one at a time and
append it to remaining (n-1)! permutations.

Efficiency:
-----------
O(n!) and as well we have expensive swaps

Strategy used:
--------------
Decrease and Conquer(decrease by 1)

*/

#include <stdio.h>
#include <stdlib.h>

// Global n
int gn;

void permute(int a[], int n)
{
    if (n == 1)
    {
        int i;
        for(i = 0; i < gn; i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }

    int i;
    int temp;
    for(i = 0; i < n; i++)
    {
        // Remove the ith item
        temp = a[i];
        a[i] = a[n-1];
        a[n-1] = temp;
        
        permute(a, n-1);
        
        // Restore it for the next round
        temp = a[i];
        a[i] = a[n-1];
        a[n-1] = temp;

    }
}

int main()
{
    int a[5] = {1, 2, 3};
    int n = 3;
    gn = n;

    permute(a, n);

    return 0;
}
