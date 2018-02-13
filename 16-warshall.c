#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int i, j, k;
    int R[5][5] = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0},
                    {0, 1, 0, 1, 0}
                };

     printf("The supplied input is\n");
     for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", R[i][j]);
        }
        printf("\n");
    }


    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(R[i][j] != 1){
                    if(R[i][k] == 1 && R[k][j] == 1)
                        R[i][j] = 1;
                }
            }
        }
    }

    printf("Transitive Closure:\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j<= n; j++){
            printf("%d\t", R[i][j]);
        }
        printf("\n");
    }
    return 0;
}
