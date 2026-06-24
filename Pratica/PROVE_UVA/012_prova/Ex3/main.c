#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int input_values[MAX_INPUT]; 
    int index = 0;
    long long DP[MAX]; 

    printf("SAMPLE INPUT:\n");
    // Leggiamo i valori finché non finisce il file (EOF)
    while (index < MAX_INPUT && scanf("%d", &input_values[index]) != EOF) index++;
    
    int total_cases = index;
    
    printf("\nSAMPLE OUTPUT:\n");
    for (int i = 0; i < total_cases; i++) {
        int n = input_values[i];
        // Chiamata alla tua funzione CalcolaDp
        long long m = CalcolaDp(DP, n);

        // Gestione dell'output
        if (m == 1) {
            printf("There is only 1 way to produce %d cents change.\n", n);
        } else {
            printf("There are %lld ways to produce %d cents change.\n", m, n); 
        }
    }

    system("pause");
    return 0;
}

/*
Complessità:O(numeroTest*(n*target))

Ricorrenza: DP[j]=DP[j-monetaX]+DP[j] per ogni j appartenete [monetaX,target]               oppure  monete<=j<=target         
                                                                                            oppure  posso scrivere in modo equivalente(j=moneta tale che j<=target)
*/