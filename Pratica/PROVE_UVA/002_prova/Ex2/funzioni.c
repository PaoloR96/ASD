#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
//{4, 6, 4, 3, 2, 2, 1, 1}
void trovaSomme(int A[], int n, int target, int index, int attuale[], int size, int sommaCorrente, int *trovato) {
    if (sommaCorrente == target) {
        StampaArray(attuale, size);
        *trovato = 1; // Segnaliamo che abbiamo trovato almeno una soluzione
        return;
    }
    
    for (int i = index; i < n; i++) {
        if (i > index && A[i] == A[i - 1]) continue;

        if (sommaCorrente + A[i] <= target) {
            attuale[size] = A[i];
            trovaSomme(A, n, target, i + 1, attuale, size + 1, sommaCorrente + A[i], trovato);
        }
    }
}