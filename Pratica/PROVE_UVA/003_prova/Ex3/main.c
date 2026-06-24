#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int S[] = {-7, 10, 9, 2, 3, 8, 8, 6};
    int n = sizeof(S) / sizeof(S[0]);
    /*vettori dp*/
    int dp[n+1];//Memorizza la lunghezza della sottosequenza più lunga che termina all'indice i
    int p[n+1];//Memorizza l'indice del numero precedente nella sequenza, per poterla ricostruire alla fine.
    printf("SAMPLE INPUT:\n");
    StampaVettore(S,n);
    //1)Inizializzo i vettori
    initVettoriDp(dp,p,n+1);
    //2)Calcolo sequenza
    CalcolaDp(S,dp,p,n);
    //3)Stampa output
    int max_len = 0;
    int last_index = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] >= max_len) { // >= garantisce di prendere l'ultimo in caso di parità
            max_len = dp[i];
            last_index = i;
        }
    }
    printf("SAMPLE OUTPUT:\n");
    printf("%d\n",max_len);
    printf("-\n");
    StampaSequenza(S,p,last_index); 


   

    system("pause");
    return 0;
}
/*Complessità: o(N^2)*/
/*Ricorrenza:dp[i] = 1 + massimo tra tutti i dp[y] tali che:
- 0 <= y < i && A[y] < A[i]*/