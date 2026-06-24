#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int dp[MAX_C+1][MAX_M+1]; // dp[categoria][denaro_speso]
   CasiTest test = {
        .budget = 100,
        .num_indumenti = 4,
        .num_modelli = {3, 2, 4, 4},
        .prezzi = {
            {8, 6, 4},
            {5, 10},
            {1, 3, 3, 7},
            {50, 14, 23, 8}
        }
    };
    //1.Stampa valori
    printf("SAMPLE INPUT:\n");
    stampaCasiTest(test);
    //2.Init matrice dp
    inizializzaDp(dp, test.num_indumenti, test.budget);
    //3. Calcola dp
    int massimo=calcolaDp(dp,test);
    if (massimo != -1) {
        printf("%d\n", massimo);
    } else {
        printf("no solution\n");
    }
    system("pause");
    return 0;
}
/*
Complessità:O(C × M × K)

Dove:
C = Numero di indumenti
M = Budget disponibile
K = Numero di modelli per ogni indumento



Funzione di Ricorrenza:

1. Caso Base (Primo indumento, i = 0):

Per ogni modello k della prima categoria di indumenti (i=0):

    dp[0][prezzo_{0,k}] = 1     se prezzo_{0,k} <= M

2. Passo Ricorsivo (Per gli indumenti successivi, 1 <= i < C):

Una spesa totale j è raggiungibile al passo i se esiste almeno un modello k della categoria attuale
tale che la spesa rimanente fosse raggiungibile al passo precedente:

    dp[i][j] = OR su tutti i k ( dp[i-1][ j - prezzo_{i,k} ] )

Dove:
- j è la spesa corrente (0 <= j <= M)
- prezzo_{i,k} è il prezzo del modello k per l'indumento i
- L'operatore OR logico (∨) indica che basta una sola combinazione precedente valida.




*/