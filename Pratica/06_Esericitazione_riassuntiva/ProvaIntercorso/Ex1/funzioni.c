#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", A[i]);
}

void CalcolaOccorenze(int A[], int size) {
    int k = A[0];      // Il primo numero dell’input è il valore da cercare (K)
    int r = A[1];      // Il secondo numero è la dimensione logica del vettore di dati

    // Avvia il conteggio con Divide et Impera:
    // - Gli elementi del vettore iniziano a partire dall'indice 2 (dopo K e la dimensione)
    // - L'ultimo indice dell'array dei dati è 2 + r - 1
    int occorrenze = Conteggio(A, k, 2, 2 + r - 1);

    // Stampa il vettore e il numero di occorrenze trovate
    printf("Per il vettore:\n");
    StampaArray(A, size);
    printf("Il numero di occorrenze: %d", occorrenze);
    printf("\n");
}

//----------------------------------------------------
// Funzione ricorsiva che implementa l'approccio Divide et Impera
// per contare le occorrenze di k in A[p..r]
//----------------------------------------------------
int Conteggio(int A[], int k, int p, int r) {
    // Caso base 1: intervallo vuoto → nessuna occorrenza
    if (p > r)  
        return 0;

    // Caso base 2: intervallo di un solo elemento
    // Ritorna 1 se l'elemento è uguale a k, altrimenti 0
    if (p == r)
        return (A[p] == k);

    // Passo ricorsivo: dividiamo l'intervallo a metà
    int q = (p + r) / 2;

    // Conteggio delle occorrenze nella parte sinistra e destra
    int sinistra = Conteggio(A, k, p, q);
    int destra   = Conteggio(A, k, q + 1, r);

    // Combino i risultati (somma dei due conteggi)
    return sinistra + destra;  
}