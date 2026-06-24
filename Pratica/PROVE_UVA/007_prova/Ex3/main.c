#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int N = 5;  // lunghezza della sequenza
    int seq[MAX_N] = {12, -4, -10, 4, 9};
    int dp[MAX_N];
    //1.Inizializzodp[N+1]
    initDp(dp,N);
    //2.Ricerca DP MAX somma
    int risultato = CalcolaDp(dp, seq, N);
    if (risultato > 0) {
        printf("The maximum winning streak is %d.\n", risultato);
    } else {
        printf("Losing streak.\n");
    }
   
    system("pause");
    return 0;
}
/*
Complessità: O(N)
Ricorrenza:dp[i]=max(seq[i],dp[i-1]+seq[i]);
*/