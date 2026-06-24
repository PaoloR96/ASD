#include <stdio.h>
#include "funzioni.h"

// matrice DP globale
int DP[N+1][S+1];

// Inizializza la matrice DP a 0
void InizializzaDp(){
    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= S; j++)
            DP[i][j] = 0;
}

// Costruisce la tabella DP per il problema dello zaino
void CostruisciDP(Oggetto zaino[]){
    for(int i = 1; i <= N; i++){
        for(int x = 0; x <= S; x++){
           if(zaino[i-1].peso <= x){
                // Prendere o non prendere l'oggetto i
                int prendi = zaino[i-1].valore + DP[i-1][x - zaino[i-1].peso];
                int nonPrendi = DP[i-1][x];
                DP[i][x] = (prendi > nonPrendi) ? prendi : nonPrendi;
            } else {
                // Non posso prendere l'oggetto
                DP[i][x] = DP[i-1][x];
            }  
            
        }
    }



}

// Stampa la tabella DP
void StampaDP(){
    printf("\nTabella DP[i][x]:\n\n");

    // intestazione colonne (capacità dello zaino)
    printf("i\\x\t");
    for(int x = 0; x <= S; x++)
        printf("%4d", x);
    printf("\n");

    // stampa righe (oggetti)
    for(int i = 0; i <= N; i++){
        if(i == 0)
            printf("0\t"); // riga iniziale senza oggetti
        else
            printf("%d\t", i); // oggetto i

        for(int x = 0; x <= S; x++)
            printf("%4d", DP[i][x]);

        printf("\n");
    }
}