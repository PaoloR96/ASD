#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int dp[N];
    int monete[5] = {1, 5, 10, 25, 50};
    int target[2] = {11, 26};
    for (int index = 0; index < 2; index++){
            //Inizializzo la dp
            InitDp(dp,target[index]);
            //Calcolo il numero di modi
            CalcoloModi(dp,monete,target[index]);
            //Stampo il numero di modi
            printf("%d\n",dp[target[index]]);
    }
    
    system("pause");
    return 0;
}
/*

Complessità Temporale: O(K*N*M)dove:
        K numero casi di test;
        N è il limite massimo (7489); 
        M è il numero di monete (5).

Ricorrenza:dp[i]=dp[i]+dp[i-monetaAtt],dove:
        dp[i]:Non prendo la moneta attuale;
        dp[i]+dp[i-monetaAtt]:Prendo la moneta attuale;
*/