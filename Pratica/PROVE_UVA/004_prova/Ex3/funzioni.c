#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void stampaCasiTest(CasiTest t) {
    // prima riga: budget e numero indumenti
    printf("%d %d \n", t.budget, t.num_indumenti);

    // per ogni indumento
    for (int i = 0; i < t.num_indumenti; i++) {
        // stampa numero modelli
        printf("%d ", t.num_modelli[i]);

        // stampa prezzi
        for (int j = 0; j < t.num_modelli[i]; j++) {
            printf("%d ", t.prezzi[i][j]);
        }

        printf("\n");
    }
}
void inizializzaDp(int dp[MAX_C+1][MAX_M+1], int c, int m) {
    // inizializza tutta la matrice a 0 (falso)
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
}




int calcolaDp(int dp[MAX_C+1][MAX_M+1],CasiTest t){
    // --- 1. Inizializzazione (Primo indumento: i = 0) ---
    for (int m = 0; m < t.num_modelli[0]; m++) {
        int prezzoAtt = t.prezzi[0][m];
        if (prezzoAtt <= t.budget) {
            dp[0][prezzoAtt] = 1; // La spesa è possibile
        }
    }

    //--- 2. Fase DP (Indumenti successivi: da i = 1 a num_indumenti) ---
    for (int i = 1; i < t.num_indumenti; i++){//per ogni indumento i
        for (int m = 0; m < t.num_modelli[i]; m++){//per ogni modello m
            int prezzoAtt=t.prezzi[i][m];
            for (int  k= 0; k <=t.budget; k++){// vado ad aggiornare la dp[i-1][k] se prezzoAtt+k<=budget
                // Se era possibile raggiungere la spesa 'k' con l'indumento precedente
                // e aggiungendo il modello attuale non superiamo il budget
                if(dp[i-1][k]==1 &&(k+prezzoAtt)<=t.budget)dp[i][k + prezzoAtt] = 1;
            }
        }
    }
    //----3. Trova il max ----
    for (int i = t.budget; i >=0; i--){
        if(dp[t.num_indumenti - 1][i]==1)return i;
    }
    return -1;
}

     
