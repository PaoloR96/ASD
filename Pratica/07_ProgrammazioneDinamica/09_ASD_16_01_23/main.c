#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int casiTest = 0;
    bool dp[SIZE];
    printf("Sample Input:\n");
    scanf("%d", &casiTest);

    int SequenzaTest[50][50];   // max 50 casi e 50 monete ciascuno
    int dimensione[1000];          // numero di monete per ogni caso

    // Lettura input
    for (int index = 0; index < casiTest; index++) {
        scanf("%d", &dimensione[index]);   // numero di monete
        for (int i = 0; i < dimensione[index]; i++) {
            scanf("%d", &SequenzaTest[index][i]); // valori monete
        }
    }

    // Elaborazione e output
    printf("\nSample Output:\n");
    for (int index = 0; index < casiTest; index++) {
        int M = dimensione[index];  // numero di monete
        int somma = Somma(SequenzaTest[index], M);
        int target = somma / 2;

        InitDp(dp, target + 1);  // inizializza dp[0..target]
        int val = CalcolaDp(dp, SequenzaTest[index], M, target);

        int diff = somma - 2 * val;
        printf("%d\n", diff);
    }
    system("PAUSE");
    return 0;
}

/*

Complessità:O(n⋅target) 
con n = numero di monete (M in codice)
    target = metà della somma totale delle monete (somma/2)

Ricorrenza:dp[x] = dp[x] || dp[x - c];

*/