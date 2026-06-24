#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InitDP(long long DP[MAX_N][MAX_M][MAX_D], int n, int m, int d) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < d; k++) {
                DP[i][j][k] = 0;
            }
        }
    }
}
long long CalcolaDP(long long DP[MAX_N][MAX_M][MAX_D],int N[MAX_N] ,int n, int m, int d){
    //Inizializzo DP
    InitDP(DP, n, m, d);
    //1.caso base
    DP[0][0][0]=1;
    //2.ricorrenza    
    for (int i = 1; i <= n; i++){// Per ogni numero della lista "i"
            int valoreX=N[i-1];// Prende l'i-esimo numero dall'input
            // Calcoliamo il resto del numero corrente rispetto a D
            int restoCorrente = ((valoreX % d) + d) % d;
            for (int j = 0; j <= m; j++){// Quanti numeri stiamo scegliendo
                for (int k = 0; k < d; k++){ //Tutti i possibili resti
                    // Opzione 1: NON includiamo il numero corrente i-esimo
                    DP[i][j][k] += DP[i - 1][j][k];
                    if (j>0){
                        // Opzione 2: Includiamo il numero i-esimo
                        int restoPrecedente = (k - restoCorrente + d) % d;
                        DP[i][j][k] += DP[i - 1][j - 1][restoPrecedente];
                    }
                }
            }
    }
    // Il risultato è il numero di modi per scegliere M numeri con resto 0 
    return DP[n][m][0];
}
