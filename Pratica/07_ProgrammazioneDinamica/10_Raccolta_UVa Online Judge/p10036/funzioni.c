#include <stdio.h>
#include "funzioni.h"

void InitDp(int dp[DIM_N][DIM_K],int K, int N){
    for (int i = 0; i < N; i++)
        for (int r = 0; r < K; r++)
            dp[i][r]=0;    
}

void CalcolaDp(int dp[DIM_N][DIM_K],int C[],int K, int N){
    // 1.Caso base: primo numero
    int restoIniziale = ((C[0] % K) + K) % K;
    dp[0][restoIniziale] = 1;
    //2.Ricorrenza:
    for (int i = 1; i < N; i++){
        int restoCorrente = ((C[i] % K) + K) % K;
        for (int r = 0; r < K; r++) { // Controlliamo tutti i resti della riga precedente
            if (dp[i-1][r] == 1) {
                // Opzione +
                int somma = (r + restoCorrente) % K;
                dp[i][somma] = 1;

                // Opzione -
                int differenza = (r - restoCorrente + K) % K;
                dp[i][differenza] = 1;
            }
        }
    }
}
