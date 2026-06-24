#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void InitDp(int dp[], int dim) {
    for (int i = 0; i < dim; i++) {
        dp[i] = 0;
    }
}

void CalcoloModi(int dp[], int monete[],int limiteMax){
    //Caso base: dp[0]=0
    dp[0]=1;
    //Ricorrenza
    for (int x = 0; x < 5; x++){ //con questo indice andiamo a gestire le x monete da confrontare
            int monetaAtt=monete[x];
            for (int i = monetaAtt; i <= limiteMax; i++)dp[i]=dp[i]+dp[i-monetaAtt];
    }
}