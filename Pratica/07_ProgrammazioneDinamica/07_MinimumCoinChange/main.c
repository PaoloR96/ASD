#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
    int coins[N] = {1,3,4};
    int dp[2*C + 1];
    
    InitDp(dp);
    int result = DpMinimumCoin(dp, coins);
    
    printf("Minimo numero di monete: %d\n", result);

    system("PAUSE");
    return 0;
}

/* La complessità temporale è O(C * N):
   - C = somma target (valore da raggiungere)
   - N = numero di tipi di monete
   Per ogni valore da 1 a C, si prova ogni moneta. */


   /*
   
 Ricorrenza:

  1)dp[x] = minimo numero di monete necessarie per ottenere la somma x

 2)Caso base:
   dp[0] = 0(perché servono 0 monete per fare somma 0)


 3) Ricorrenza:  dp[x] = min { dp[x - c] + 1 | c ∈ coins, c ≤ x } Cioè minimo tra tutte le possibilità di scegliere una moneta c
                                                                  e aggiungere 1 al numero minimo di monete per ottenere x - c

   */