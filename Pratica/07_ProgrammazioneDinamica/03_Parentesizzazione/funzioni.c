#include <stdio.h>
#include <limits.h>
#include "funzioni.h"

// --- Definizione delle variabili globali ---
int DP[N][N]; 
int S[N][N];

// --- Funzioni ---
void InizializzaDp(int DP[N][N], int n){
    for (int i = 0; i < N; i++){
         for (int j = 0; j < N; j++){
            DP[i][j]=0;
         }     
    }
    
}

void stampaDP(int DP[N][N], int n) {

    printf("\nTabella DP(i,j):\n\n");
    printf("i\\j\t");
    for (int j = 1; j <= n; j++)
        printf("%4d", j);
    printf("\n ");
    for (int i = 1; i <= n; i++) {
        printf("%3d\t", i);
        for (int j = 1; j <= n; j++) {
            if (j < i)
                printf("   -");
            else
               printf("%4d", DP[i][j]);

        }
        printf("\n");
    }
}

// stampa parentesizzazione ottima
void stampaParentesi(int S[N][N], int i, int j) {

    if(i==j) {
        printf("A%d",i);
        return;
    }

    printf("(");

    stampaParentesi(S,i,S[i][j]);
    stampaParentesi(S,S[i][j]+1,j);

    printf(")");
}

void matrixChain(int C[], int n){
    for (int diag = 2; diag <= n; diag++){ //andiamo a governare e definire ogni volta la diagonale
         for(int i=1;i<=n-diag+1;i++) { //inidice i tiene traccia dell'indice iniaziale di ogni diagonale diag
            int j = i + diag - 1;  //definisco l'indice finale della  diagonale
            DP[i][j]=INT_MAX;
            for (int k = i; k <j; k++){ // vado a valutare tutti gli elementi (i,j)
                  int costo = DP[i][k] + DP[k+1][j] + C[i-1]*C[k]*C[j]; //calcolo del costo
                  if(costo < DP[i][j]) {
                    DP[i][j]=costo;
                    S[i][j]=k;
                }
            }     
        }
    }    
}