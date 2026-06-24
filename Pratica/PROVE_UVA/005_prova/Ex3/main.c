#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int l_input;
    int dp[N_MAX][N_MAX];

    // Legge la lunghezza finché non è 0 
    while (scanf("%d", &l_input) == 1 && l_input != 0) {
        CasoTest test;
        test.l = l_input;
        
        // Legge il numero di tagli n
        scanf("%d", &test.n);
        
        // Legge i punti di taglio ci 
        for (int i = 0; i < test.n; i++) {
            scanf("%d", &test.ci[i]);
        }

        // 1. Prepara l'array result con 0 e l
        test = buildCutsStruct(test);

        // 2. Calcola il costo minimo
        int val = CalcolaDp(dp, test);

        // 3. Stampa nel formato richiesto 
        printf("The minimum cutting is %d.\n", val);
    }
    system("PAUSE");
    return 0;
}
/*Complessità:O(n_punti^3) con n_punti numero di punti da tagliare*/
/*
Ricorrenza dp[i][j] = minimo(dp[i][j], costoCorrente);
con costoCorrente = dp[i][k] + dp[k][j] + lunghezzaPezzo;

*/