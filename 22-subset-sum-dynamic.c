#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subset_sum(int a[], int n, int sum)
{
    int ss[n+1][sum+1];
    int i,j;

    // When sum is 0, empty set is the solution
    for(i = 0; i <= n; i++)
        ss[i][0] = 1;

    // When there are no array elements, subsets are not possible
    for(j = 1; j <= sum; j++)
        ss[0][j] = 0;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= sum; j++){
            if(ss[i-1][j] == 1)
                ss[i][j] = 1;
            else
            {
                if(a[i-1] > j)
                    ss[i][j] = 0;
                else
                    ss[i][j] = ss[i - 1][j - a[i-1]];
            }
        }
    }

    return ss[n][sum];
}

int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 5, 7};
    int sum = 9;

    int result=subset_sum(a,n,sum);

    if(result)
        printf("Subset found\n");
    else
        printf("Subset not found\n");

    return 0;
}
