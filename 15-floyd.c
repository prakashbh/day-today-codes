#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int i, j, k;
    int D[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 999, 3, 999},
                    {0, 2, 0, 999, 999},
                    {0, 999, 7, 0, 1},
                    {0, 6, 999, 999, 0}
                };

     printf("The supplied input is\n");
     for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }


    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if((D[i][k] + D[k][j]) < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
        }
    }

    printf("All pair shortest paths:\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
