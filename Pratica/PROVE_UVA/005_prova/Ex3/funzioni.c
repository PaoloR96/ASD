#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header




CasoTest buildCutsStruct(CasoTest test) {
    test.result[0] = 0;
    for (int i = 0; i < test.n; i++)test.result[i + 1] = test.ci[i];
    test.result[test.n + 1] = test.l;
    return test;
}

int minimo(int a, int b) {
    return (a < b) ? a : b;
}



void InitDp(int dp[N_MAX][N_MAX] ,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
}

int CalcolaDp(int dp[N_MAX][N_MAX] ,CasoTest T){
        int n_punti = T.n + 2; // Numero totale di punti (estremi + tagli)
        // Inizializziamo la DP a 0 (i segmenti senza tagli interni costano 0)
        InitDp(dp, n_punti);
        // d = distanza tra gli indici (es. se d=2, stiamo guardando dp[i][i+2])
        for (int d = 2; d < n_punti; d++) {
            for (int i = 0; i < n_punti - d; i++) {
                int j = i + d;
                //Inizializziamo con un valore molto alto per trovare il minimo
                dp[i][j] = INT_MAX; // Un valore superiore al costo massimo possibile
                // Lunghezza del pezzo di legno attuale che stiamo tagliando
                int lunghezzaPezzo = T.result[j] - T.result[i]; 
                // k è il punto dove effettuiamo il primo taglio in questo 
                for (int k = i + 1; k < j; k++) {
                        int costoCorrente = dp[i][k] + dp[k][j] + lunghezzaPezzo;
                        // Aggiorniamo il minimo usando la tua funzione
                        dp[i][j] = minimo(dp[i][j], costoCorrente);
                }

            }
        }
        // Il risultato finale è il costo minimo per l'intera asta (da 0 a n_punti-1) 
        return dp[0][n_punti - 1];
}
