#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void GeneraCombinazioni(int S[],int k,int n){
    int comb[k];
    BackTracking(S,n,k,0,comb,0);
}
void BackTracking(int S[], int n, int k, int start, int comb[], int pos) {
    /* Caso base:
       Se ho già selezionato k elementi (pos == k),
       significa che la combinazione è completa → la stampo e termino questa chiamata */
    if (pos == k) {
        StampaCombinazioni(comb, k);
        return;
    } else {
        /* Caso ricorsivo:
           Scorro tutti gli elementi di S a partire da 'start'.
           Ogni iterazione rappresenta una nuova scelta per la posizione corrente 'pos'. */
        for (int i = start; i < n; i++) {

            /* Inserisco l’elemento S[i] nella combinazione in costruzione */
            comb[pos] = S[i];

            /* Richiamo ricorsivamente BackTracking per riempire la posizione successiva.
               Uso 'i + 1' come nuovo valore di 'start' per evitare ripetizioni
               e mantenere l’ordine crescente (cioè, non torno mai indietro). */
            BackTracking(S, n, k, i + 1, comb, pos + 1);
        }
    }
}


void StampaCombinazioni(int comb[], int k) {
    printf("[ ");
    for (int i = 0; i < k; i++) {
        printf("%d ", comb[i]);
    }
    printf("]\n");
}