#include <stdio.h>
#include "funzioni.h"

/* inizializza l'array dp */
void InitDp(int dp[2*C + 1]){
    dp[0] = 0;  // base case
    for (int i = 1; i <= 2*C; i++)
        dp[i] = INT_MAX;
}
int min(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}

/* calcola il minimo numero di monete per ottenere la somma C */
int DpMinimumCoin(int dp[2*C + 1], int coins[N]){
    for (int i = 1; i <= C; i++){
        for (int coin = 0; coin < N; coin++){
            //verifica che posso usare la moneta senza uscire dai limiti && il sottoproblema esiste davvero.
            if (coins[coin] <= i && dp[i - coins[coin]] != INT_MAX){
                dp[i] = min(dp[i], dp[i - coins[coin]] + 1);
            }
        }
    }

    if (dp[C] == INT_MAX) 
        return -1;  // se impossibile formare C
    else
        return dp[C];
}

