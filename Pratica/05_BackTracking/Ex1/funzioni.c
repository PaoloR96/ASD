#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
void GeneraSequenza(int n){
    int S[n];
    BackTracking(n,0,S);

}
void BackTracking(int n, int pos, int S[]) {
    /* Caso base: se ho generato tutti gli elementi della sequenza, la stampo */
    if (pos == n) {
        StampaSequenza(S, n);
        return;
    } else {
        /* Passo ricorsivo: genero tutte le possibili sequenze binarie */

        // Aggiungo 0 alla posizione corrente e continuo
        S[pos] = 0;
        BackTracking(n, pos + 1, S);

        // Aggiungo 1 alla posizione corrente e continuo
        S[pos] = 1;
        BackTracking(n, pos + 1, S);
    }              
}

void StampaSequenza(int S[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("]\n");
}
