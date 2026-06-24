#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int dp[MAX_DP];
    int m=3;//numero di monete nel sacchetto
    int s[MAX_MONETE]={2, 3, 5}; //ogni numero indica il valore di una moneta
    //1.Sommo moneta all'intero del sacchetto
    int somma=Somma(s,m);
    int target=somma/2;
    //2.Inizializzo dp[target+1];
    InitDP(dp,target+1);
    //3.Calcola dp
    int val= CalcolaDP(dp,s,target,m);
    int diff = (somma - val)-val;
    printf("%d",diff);


    system("pause");
    return 0;
}
/*
Complessità:  O(M*Target)

Ricorrenza:DP[i] = DP[i] OR DP[i - monetaAtt]

*/