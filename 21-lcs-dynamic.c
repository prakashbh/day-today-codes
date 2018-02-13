#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Longest Common Subsequence Problem

Examples:
---------

str1="classic"
str2="music"
LCS=3 for the pattern "sic"


str1="eabcde"
str2="aabfcde"
LCS=3 for the pattern "abc"

*/


int get_lcs(char *str1, char *str2, int len1, int len2)
{
    int i, j;
    int lcs[len1+1][len2+1];

    // starting with base cases of
    // First string is empty
    for(i = 0 ; i < len2; i++)
        lcs[0][i] = 0;

    // Second string empty
    for(i = 0; i <= len1; i++)
        lcs[i][0]=0;


    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            // When charatcers of both string match
            if(str1[i-1] == str2[j-1])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = lcs[i-1][j] > lcs[i][j-1]  ? lcs[i-1][j] : lcs[i][j-1];
        }
    }

    return lcs[len1][len2];
}


int main()
{
    char str1[50] = "lmnop";
    char str2[50] = "lmmnoop";

    int result;
    result = get_lcs(str1, str2, strlen(str1), strlen(str2));
    printf("LCS for supplied input is:\n");
    printf("%d\n", result);

    return 0;
}
