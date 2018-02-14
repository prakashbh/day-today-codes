#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Counts the number of ways in which the given score can be reached using 3, 5 and 10.
Technique used: Dynamic Programming
*/
int count_number_of_ways(int score)
{
    int i;
    int result[score+1];

    // Initialize all the entries with 0
    memset(result, 0, sizeof(int) * (score+1));

    // There is one way to reach NO score
    result[0] = 1;

    // Count the ways using 3
    for(i = 3; i <= score; i++)
        result[i] = result[i] + result[i-3];

    // Count the ways using 3 and 5
    for(i = 5; i <= score; i++)
        result[i] = result[i] + result[i-5];

    // Count the ways using 3, 5 and 10
    for(i = 10; i <= score; i++)
        result[i] = result[i] + result[i-10];

    return result[score];
}

int main()
{
    int score = 15;
    int result = count_number_of_ways(score);
    printf("The number of ways are:\n");
    printf("%d\n", result);

    return 0;
}
