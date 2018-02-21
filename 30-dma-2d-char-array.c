#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Say if we want to allocate memory for a 2D char array
    // string[10][50];

    int rows =  10;
    int cols = 50;
    int i;
    
    // Allocate for row of pointers
    char **string = malloc(rows * sizeof(char *));
    // For each row, get the number of columns
    for(i = 0; i < rows; i++)
        string[i] = malloc(cols * sizeof(char));

    return 0;
}
