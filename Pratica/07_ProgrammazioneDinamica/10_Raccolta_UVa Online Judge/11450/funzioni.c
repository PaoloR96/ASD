#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

void StampaInput(Capi A[], int numCapi) {
    for(int i = 0; i < numCapi; i++) {
        printf("%d ", A[i].size); 
        for(int j = 0; j < A[i].size; j++) {
            printf("%d ", A[i].dati[j]);
        }
        printf("\n");
    }
}

void InitDP(int dp[MAX_C][MAX_M]) {
    for(int i = 0; i < MAX_C; i++) {
        for(int j = 0; j < MAX_M; j++) {
            dp[i][j] = 0;
        }
    }
}

int CalcoloDp(int dp[MAX_C][MAX_M], Capi A[], int numCapi, int budget) {
    // 1. CASO BASE: Primo capo (riga 0) 
    for (int j = 0; j < A[0].size; j++) {
        int prezzo = A[0].dati[j];
        if (prezzo <= budget) dp[0][prezzo] = 1;  
    }

    // 2. RICORRENZA: Capi successivi
    for (int i = 1; i < numCapi; i++) { 
        for (int s = 0; s <= budget; s++) {
            if (dp[i-1][s] == 1) { // Se la spesa 's' era possibile al passo precedente
                for (int k = 0; k < A[i].size; k++) { // Ciclo sui modelli del capo CORRENTE
                    int prezzoModello = A[i].dati[k];
                    if (s + prezzoModello <= budget) {
                        dp[i][s + prezzoModello] = 1;
                    }
                }
            }
        }
    }

    // 3. RICERCA SOLUZIONE: Scansione ultima riga dal massimo
    for (int s = budget; s >= 0; s--) {
        if (dp[numCapi - 1][s] == 1) return s;
    }

    return -1; // "no solution"
}

/*

1)Complessità :O(C * M * K)
    C: Numero di capi da acquistare (fino a 20)
    M: Budget disponibile (fino a 200)
    K: Numero di modelli per ogni capo (fino a 20)

2)Definizione della Ricorrenza:
    reachable(i, s) indica se è possibile acquistare i primi i capi spendendo esattamente s.

    Caso Base (primo capo, i = 0):
        - reachable(0, prezzo) = true per ogni prezzo dei modelli del capo 0, se prezzo <= M
    Passo Ricorsivo (i > 0):
        - reachable(i, s) = true se esiste almeno un modello k del capo i tale che reachable(i-1, s - prezzo_i,k) = true
        - Consideriamo solo i casi con s - prezzo_i,k >= 0

*/