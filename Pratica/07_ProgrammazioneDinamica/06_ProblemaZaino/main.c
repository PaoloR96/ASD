#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
    // Definizione oggetti
    Oggetto zaino[N];
    zaino[0].peso = 1; zaino[0].valore = 1;
    zaino[1].peso = 3; zaino[1].valore = 4;
    zaino[2].peso = 4; zaino[2].valore = 5;
    zaino[3].peso = 5; zaino[3].valore = 7;

    // Inizializza la matrice DP
    InizializzaDp();

    // Costruisce la tabella DP
    CostruisciDP(zaino);

    // Stampa la tabella DP
    StampaDP();

    // Valore massimo ottenibile
    printf("\nValore massimo nello zaino: %d\n", DP[N][S]);

    system("PAUSE");
    return 0;
}