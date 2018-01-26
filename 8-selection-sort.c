#include <stdio.h>

void selection_sort(int n, int *a)
{
    int i, j, temp =0;
    int min;
    for(i=0; i <= n-2; i++) {
        min = i;
        for (j=i+1; j<= n-1; j++) {
            if(a[j]<a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[10] = {2, 6, 1, 11, 4};
    int n = 5;

    selection_sort(n, a);
    
    return 0;
}
