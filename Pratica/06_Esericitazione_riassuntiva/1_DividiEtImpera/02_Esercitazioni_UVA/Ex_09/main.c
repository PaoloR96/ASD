#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
   
    long long B[SIZE],P[SIZE], M[SIZE];    
    long long T=3,index = 0;

    printf("SAMPLE INPUT:\n");
    while (T!=0) {
        scanf("%lld",&B[index]);
        scanf("%lld",&P[index]);
        scanf("%lld",&M[index]);
        printf("\n");
        index++;
        T--;    
    }

    printf("SAMPLE OUTPUT:\n");
    CalcolaK(B,P,M,index);
    

    system("pause"); 
    return 0;
}

/* Algoritmo di exponentiation by squaring:
   ad ogni passo l’esponente P viene dimezzato → complessità O(log N) con N = P. */
