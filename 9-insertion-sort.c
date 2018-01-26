#include <stdio.h>

void insertion_sort(int n, int *a)
{
    int i, j;
    int v;
    for(i=1; i <= n-1; i++) {
        v = a[i];
        j = i-1;
        while( j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = v;
    }
}

int main()
{
    int a[10] = {2, 6, 1, 11, 4};
    int n = 5;

    insertion_sort(n, a);
    
    return 0;
}
