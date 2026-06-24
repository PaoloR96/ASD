#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InitDP(long long DP[MAX_M][MAX_D], int n, int m, int d) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < d; k++) {
                DP[j][k] = 0;
            }
        }
}

long long CalcolaDP(long long DP[MAX_M][MAX_D],int N[MAX_N] ,int n, int m, int d){
    //Inizializzo DP
    InitDP(DP, n, m, d);
    //1.caso base
    DP[0][0]=1;
    //2.ricorrenza    
    for (int i = 0; i < n; i++){// per ogni numero "i" dell'input
        int restoCorrente = ((N[i] % d) + d) % d;
        for (int j = m; j >= 1; j--){
            for (int k = 0; k < d; k++){
                // Il numero di modi per avere resto k con j elementi è:
                // se stesso (non prendo il numero i) + modi con (j-1) elementi e resto precedente
                int restoPrecedente = (k - restoCorrente + d) % d;
                DP[j][k] += DP[j - 1][restoPrecedente];
            }
        }
        

    }
    
    // Il risultato è il numero di modi per scegliere M numeri con resto 0 
    return DP[m][0];
}
