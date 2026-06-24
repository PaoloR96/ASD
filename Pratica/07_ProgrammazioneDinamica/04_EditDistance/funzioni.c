#include <stdio.h>
#include <limits.h>
#include "funzioni.h"

// --- Variabili globali ---
int DP[DIM_X+1][DIM_Y+1];  // matrice DP

// --- Funzioni ---
int min3(int a, int b, int c){
    int m = a;
    if(b < m) m = b;
    if(c < m) m = c;
    return m;
}

void InizializzaDp(){
    for(int i = 0; i <= DIM_X; i++)
        for(int j = 0; j <= DIM_Y; j++)
            DP[i][j] = 0;
}

void EditDistance(char x[DIM_X], char y[DIM_Y]){
    // 1. Inizializza prima riga e prima colonna
    for(int i = 0; i <= DIM_X; i++) DP[i][0] = i;  // delete
    for(int j = 0; j <= DIM_Y; j++) DP[0][j] = j;  // insert

    // 2. Riempie la matrice
    for(int i = 1; i <= DIM_X; i++){
        for(int j = 1; j <= DIM_Y; j++){
            int costo_replace = (x[i-1] == y[j-1]) ? 0 : 1; // copy = 0, replace = 1
            DP[i][j] = min3(
                DP[i-1][j] + 1,          // delete
                DP[i][j-1] + 1,          // insert
                DP[i-1][j-1] + costo_replace  // replace/copy
            );
        }
    }
}

void StampaDP(char x[DIM_X], char y[DIM_Y]){
    printf("\nTabella DP(i,j):\n\n");

    // Intestazione colonne (caratteri di y)
    printf("i\\j\t");
    for(int j = 0; j < DIM_Y; j++)
        printf("%4c", y[j]);
    printf("\n");

    // Riga per riga
    for(int i = 0; i < DIM_X; i++){
        printf("%3c\t", x[i]);  // intestazione riga con carattere di x
        for(int j = 1; j <= DIM_Y; j++){
            printf("%4d", DP[i+1][j]);  // corrispondenza con DP[i+1][j]
        }
        printf("\n");
    }
}