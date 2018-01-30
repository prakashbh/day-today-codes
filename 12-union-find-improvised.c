#include<stdio.h>
#define n 6

int arr[n];

void initialize()
{
    int i;
    for(i = 0; i<n; i++)
        arr[i] = i;
}

int root(int i)
{
    while(arr[i] != i)
        i = arr[i];
    return i;
}

int Find(int a, int b)
{
    if(root(a) == root(b))
        return 1;
    else
        return 0;
}

int Union(int a ,int b)
{
    int root_a;
    int root_b;
    root_a = root(a);
    root_b = root(b);
    arr[ root_a ] = root_b ;
}

int main()
{
    initialize();
    Union(1,0);
    Union(0,2);
    Union(3,4);
    Union(1,4);

    int i;
    // Result should be
    // 2 0 4 4 4 5
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    int status;
    status = Find(1,4);
    // Result should be
    // 1
    printf("\n%d", status);

    status = Find(3,5);
    // Result should be
    // 0
    printf("\n%d", status);

    return 0;
}
