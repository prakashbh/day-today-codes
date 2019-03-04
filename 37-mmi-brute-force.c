/*
Modulo Multiplicative Inverse (MMI) of a number y is z iff
(z * y) % M = 1

Example 1:
If M = 7 and y =  4,
then (z * 4) % 7 = 1  ==> Z = 2

Example 2:
If M = 11 and y = 7,
then (z * 7) % 11 = 1  ==> z = 8

*/

#include <stdio.h>
#define M 11

int mmi_brute_force(int y)
{
    int i = 1;
    while(i < M)
    {
        if(((long long)i * y ) % M == 1)
            return i;
        i++;
    }
    return -1;
}

int main()
{
    int y = 7;
    int mmi = mmi_brute_force(y);
    if (mmi == -1)
        printf("MMI does not exist\n");
    else
        printf("MMI is %d\n", mmi);
    return 0;
}
