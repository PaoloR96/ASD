#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header


void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) scanf("%d",&A[i]);
}

int TrovaValore(int A[], int start, int end, int k){
    /* Caso base: nessun elemento nell'intervallo */
    if(start > end) return 0;

    /* Calcolo dell'indice centrale */
    int mid = (start + end) / 2;

    /* Se l'elemento centrale è > k, abbiamo trovato la condizione */
    if(A[mid] > k) return 1;

    /* Se A[mid] ≤ k, eventuali valori > k possono trovarsi solo a destra */
    if(A[mid] <= k) return TrovaValore(A, mid + 1, end, k);

    /* (Caso teorico) Se A[mid] < k cercherei a sinistra — 
       ma questo ramo in pratica non verrà mai eseguito
       perché A[mid] ≤ k e A[mid] > k coprono tutti i casi */
    return TrovaValore(A, start, mid - 1, k);
}
