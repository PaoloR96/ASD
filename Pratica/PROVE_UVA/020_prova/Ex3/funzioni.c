#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"

// Definizione della matrice globale
bool preso[MAX][MAX_N];

void InizializzaDP(int DP[MAX_N], int N) {
    for (int i = 0; i <= N; i++) DP[i] = 0;
    // Inizializzo la matrice delle scelte per il nuovo caso di test
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <= N; j++) preso[i][j] = false;
    }
}

int CalcolaDP(int DP[MAX_N], int Brani[MAX], int numeroBrani, int N) {
    for (int i = 0; i < numeroBrani; i++) { // per ogni brano i
        int branoX = Brani[i]; // prendo il brano attuale
        for (int j = N; j >= branoX; j--) { // con questo ogni brano j lo prendo una sola volta 
            // Verifico se conviene prendere il brano
	    //come controllo potevo mettere max(DP[j],DP[j-branoX]+branoX)
            if (DP[j - branoX] + branoX >= DP[j]) {
                DP[j] = DP[j - branoX] + branoX;
                preso[i][j] = true; // Segna che il brano i è utile per la capacità j
            }
        }
    }
    return DP[N]; // Restituisce la somma migliore trovata
}

int max2(int a, int b) {
    return (a > b) ? a : b;
}

Risultato TrovaElementiInsieme(int Brani[MAX], int capResidua, int numBrani) {
    Risultato scelti;
    int contatoreScelti = 0;
    
    // aggiorno il target (salvo la somma totale ottenuta)
    scelti.capResidua = capResidua;
    //ora devo prendere i brani
    // partiamo dall'ultimo brano inserito
    int attuale = capResidua;
    for (int i = numBrani - 1; i >= 0; i--) {
        if (attuale >= 0 && preso[i][attuale]) {
            scelti.valori[contatoreScelti++] = Brani[i]; // aggiungo il brano
            attuale -= Brani[i]; // scalo la durata dalla capacità corrente
        }
    }
    
    // salvo il contatore (numero di brani trovati)
    scelti.contatoreScelti = contatoreScelti; 
    return scelti;
}

void StampaRisultati(Risultato R) {
    // stampiamo l'array al contrario per mantenere la sequenza del CD
    for (int i = R.contatoreScelti - 1; i >= 0; i--) {
        printf("%d ", R.valori[i]);
    }
    printf("sum:%d\n", R.capResidua);
}