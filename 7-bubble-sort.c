#include <stdio.h>

void bubble_sort(int n, int *a)
{
    int i, j, temp =0;
    for(i=0; i <= n-2; i++) {
        for (j=0; j<= n-2-i; j++) {
            if(a[j+1]<a[j]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main()
{
    int a[10] = {2, 6, 8, 9, 4};
    int n = 5;

    bubble_sort(n, a);
    
    return 0;
}
