#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*Stampa Input*/
void StampaCasiTest(int V[MAX], int dim) {
    for(int i = 0; i < dim; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}
/*Inizializza Matrice DP[i][j]*/
void InizializzaDP(int DP[MAX][MAX], int dim1, int dim2) {
    for(int i = 0; i < dim1; i++) {
        for(int j = 0; j < dim2; j++) {
            DP[i][j] = 0;
        }
    }
}
/*Max*/
int max(int a, int b) {
    return (a > b) ? a : b;
}

void CalcolaDP(int DP[MAX][MAX],int T1[MAX],int dim1,int T2[MAX],int dim2){
    for (int i = 1; i <= dim1; i++){
        int valAttuale=T1[i-1];
        for (int j = 1; j <= dim2; j++){
            if(valAttuale==T2[j-1])DP[i][j]=DP[i-1][j-1]+1;// Se i raggi combaciano, aggiungiamo la piastrella alla sequenza precedente
            if(valAttuale!=T2[j-1])DP[i][j]=max(DP[i-1][j],DP[i][j-1]); // Altrimenti, manteniamo il miglior risultato ottenuto finora
        }
    }
}