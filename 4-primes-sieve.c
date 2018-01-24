/*
Reference from Wikipedia:
The algorithm finds the prime by iteratively marking as composite (i.e., not prime) the multiples of each prime, 
starting with the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers 
starting from that prime, with constant difference between them that is equal to that prime.
This is the sieve's key distinction from using trial division to sequentially test each candidate number for 
divisibility by each prime.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    long int i,j;
    int n = 100;
    int *primes;

    primes = (int *)malloc(sizeof(int) * n);
    memset(primes, 1, n*sizeof(int));

    for (i = 2;i < n; i++){
        if (primes[i]) {
            for (j = i; i * j < n; j++)
                primes[i * j] = 0;
        }
    }

    printf("\nPrime numbers in range 1 to %d are: \n", n);
    for (i = 2;i < n; i++){
        if (primes[i])
            printf("%ld ", i);
    }

return 0;
}
