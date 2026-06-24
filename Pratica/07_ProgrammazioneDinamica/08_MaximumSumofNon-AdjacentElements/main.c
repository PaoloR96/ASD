#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
    int A[N] = {3,2,7,10};
    int dp[N];
    InitDp(dp);  
    int risultato = DpCalculate(dp, A);
    printf("Massima somma di elementi non adiacenti: %d\n", risultato);
    system("PAUSE");
    return 0;
}
/*Complessità O(N-2)->O(N)
  Ricorrenza dp[x] = max(dp[x-1], A[x] + dp[x-2]);

*/