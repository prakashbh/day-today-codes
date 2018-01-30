#include<stdio.h>
#define n 10

int arr[n];

void initialize()
{
    int i;
    for(i = 0; i<n; i++)
        arr[i] = i;
}

int Find(int a, int b)
{
    if(arr[a] == arr[b])
        return 1;
    else
        return 0;
}

void Union(int a, int b)
{
    int temp;
    int i;
    temp = arr[a];
    for(i = 0; i < n; i++)
    {
        if(arr[i] == temp)
            arr[i] = arr[b];
    }
}

int main()
{
    initialize();
    Union(2,1);
    Union(4,3);
    Union(8,4);
    Union(9,3);
    Union(6,5);
    Union(5,2);

    int i;
    // Result should be
    // 0 1 1 3 3 1 1 7 3 3
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    int status;
    status = Find(0, 7);
    // Result should be
    // 0
    printf("\n%d", status);

    status = Find(1,6);
    // Result should be
    // 1
    printf("\n%d", status);

    return 0;
}
