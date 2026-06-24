#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void StampaVettore(int vettore[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", vettore[i]);
        if (i < n - 1) printf(" "); // mette uno spazio tra i numeri
    }
    printf("\n"); // a capo alla fine
}
void InizializzaDP(int DP[MAX],int DPIndici[MAX],int n){
    for (int i = 0; i < n; i++){
        DP[i]=1;
        DPIndici[i]=-1;
    }
}
int CalcolaDP(int vettore[MAX],int DP[MAX],int DPIndici[MAX],int n){
    //caso base:DP[0]=1;
    DP[0]=1;
    //caso generico
    int maxLunghezza = 1;
    int ultimoIndice = 0;
    for (int i = 1; i < n; i++){//per ogni elemento della sequenza i+1 in poi 
        int valAtt=vettore[i];//prendo il valore attuale
        for (int j = 0; j < i; j++){
            if(vettore[j]<valAtt && DP[i]<=1+DP[j]){
                DP[i]=1+DP[j];
                DPIndici[i] = j;
            }
        }
        //Usiamo >= per prendere l'ultima sequenza in caso di pareggio 
        if (DP[i] >= maxLunghezza) {
            maxLunghezza = DP[i];
            ultimoIndice = i;
        }
    }
    return ultimoIndice; // Restituisce l'indice da cui iniziare a stampare
}


void StampaSottosequenza(int vettore[MAX], int DPIndici[MAX], int i) {
    // Caso base: se l'indice è -1, abbiamo raggiunto l'inizio della catena
    if (i == -1) {
        return;
    }

    // Passa al "padre" prima di stampare (va a ritroso)
    StampaSottosequenza(vettore, DPIndici, DPIndici[i]);

    // Stampa il valore corrente (un intero per riga)
    printf("%d\n", vettore[i]);
}