#include <stdio.h>
#include "funzioni.h"

// matrice DP globale
int DP[DIM_X+1][DIM_Y+1];



// Inizializza la matrice DP
void InizializzaDp(){

    for(int i = 0; i <= DIM_X; i++)
        for(int j = 0; j <= DIM_Y; j++)
            DP[i][j] = 0;
}



// Calcolo Longest Common Subsequence
void CalcolaLCS(char x[], char y[]){

    for(int i = 1; i <= DIM_X; i++){
        for(int j = 1; j <= DIM_Y; j++){

            if(x[i-1] == y[j-1])
                DP[i][j] = DP[i-1][j-1] + 1;

            else
                DP[i][j] = (DP[i-1][j] > DP[i][j-1]) ?
                           DP[i-1][j] : DP[i][j-1];
        }
    }
}


// Stampa tabella DP
void StampaDP(char x[], char y[]){

    printf("\nTabella DP(i,j):\n\n");

    // intestazione colonne
    printf("i\\j\t");
    printf("  ");

    for(int j = 0; j < DIM_Y; j++)
        printf("%4c", y[j]);

    printf("\n");


    // riga iniziale (stringa vuota)
    printf(" \t");

    for(int j = 0; j <= DIM_Y; j++)
        printf("%4d", DP[0][j]);

    printf("\n");


    // resto della matrice
    for(int i = 1; i <= DIM_X; i++){

        printf("%c\t", x[i-1]);

        for(int j = 0; j <= DIM_Y; j++)
            printf("%4d", DP[i][j]);

        printf("\n");
    }
}