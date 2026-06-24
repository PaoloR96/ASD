#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void initVettoriDp(int dp[],int p[],int n){
    for (int i = 0; i < n; i++){
        dp[i]=1;//Ogni numero da solo è una sottosequenza di lunghezza 1.
        p[i]=-1; // -1 indica che non ha predecessori
    }
}
void StampaVettore(int A[], int n) {
    for (int i = 0; i < n; i++) printf("%d\n", A[i]);
}

void CalcolaDp(int A[],int dp[],int p[],int n){
        for (int i = 0; i < n; i++){ //rappresenta l'indice
            int actualNumber=A[i];
            for (int y = 0; y < i; y++){
                // REGOLA 1: Il numero precedente deve essere minore (strettamente crescente)
                // REGOLA 2: La nuova catena deve essere più lunga di quella che ho già
                if(A[y] < actualNumber && dp[y] + 1 > dp[i]){
                    dp[i]=dp[y]+1;// Aggiorno la lunghezza massima per l'indice i
                    p[i]=y;// Salvo l'indice del "padre" per ricostruire la scia
                }
            }     
        }
}

void StampaSequenza(int A[], int p[], int i) {
    // Caso base: se l'indice è -1, significa che non ci sono più predecessori
    if (i == -1)return;
    // Passaggio ricorsivo: vai al predecessore prima di stampare
    StampaSequenza(A, p, p[i]);
    // Stampa il numero corrente seguito da un newline
    printf("%d\n", A[i]);
}