#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int dp[W+1];             //Tabella DP (capacità max 30)
    Oggetto oggetti[N];     //Array oggetti temporaneo
    int mw[MW];            //Array pesi persone temporaneo
    int risultati[N];     //Array per SALVARE i risultati dei T test case
    
    int dim = 0;            // N oggetti
    int g = 0;              // G persone
    int numTest = 0;

   printf("SAMPLE INPUT:\n");
    if (scanf("%d", &numTest) != 1) return 0;
    int totalTest = numTest; // Archiviamo il numero totale per il secondo ciclo
    int current = 0;
    // --- PRIMO CICLO: Lettura e Calcolo Immediato ---
    while (current < totalTest) {
        // 1. Reset DP per ogni nuovo test case
        InitDP(dp);
        // 2. Lettura oggetti
        scanf("%d", &dim);
        for (int i = 0; i < dim; i++)scanf("%d %d", &oggetti[i].prezzo, &oggetti[i].peso);
        // 3. Lettura persone
        scanf("%d", &g);
        for (int i = 0; i < g; i++)scanf("%d", &mw[i]);
        // 4. Calcoliamo il risultato e lo salviamo nell'array risultati
        risultati[current] = CalcolaDP(dp, oggetti, dim, mw, g);
        current++;
    }

    // --- SECONDO CICLO: Output ---
    printf("\nSAMPLE OUTPUT:\n");
    for (int i = 0; i < totalTest; i++) {
        printf("%d\n", risultati[i]);
    }

    system("pause");
    return 0;
}

/*
Complessità temporale:
O(T * ((N * W) + G))

Dove:
T = Numero di casi di test (fino a 1000)
N = Numero di oggetti (fino a 1000)
W = Capacità massima dello zaino (fissa a 30)
G = Numero di persone nel gruppo (fino a 100)

Ricorrenza:dp[w] = max(dp[w], dp[w - peso_x] + prezzo_x);  // Usiamo max per decidere se conviene aggiungere l'oggetto x

*/