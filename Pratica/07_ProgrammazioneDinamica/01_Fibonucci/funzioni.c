#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

long long memo[MAX];   // DEFINIZIONE
long long fib(int n) {
    if(memo[n]!=-1)return memo[n]; // Se già calcolato
    if(n<=2)
        memo[n]=1;
    else
        memo[n]=fib(n-1)+fib(n-2);
    return memo[n];
}


/*
Complessità O(n) 
Ricorrenza matematica:F(n) = F(n-1) + F(n-2)
con F(1) = 1, F(2) = 1
*/

