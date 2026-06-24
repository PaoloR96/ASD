#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiVettore(int A[], int size){
    for (int i = 0; i < size; i++){ 
        printf("A[%d]=",i+1);
        scanf("%d",&A[i]);
    }
}
void TrovaValore(int A[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;

    // Verifica se c'è salto tra mid-1 e mid
    if (mid > 0 && A[mid-1] + 1 < A[mid]) {
        printf("Salto trovato tra A[%d]=%d e A[%d]=%d\n", mid-1, A[mid-1], mid, A[mid]);
        return;
    }

    // Se la sequenza è consecutiva tra start e mid, il salto deve essere a destra
    if (A[start] + (mid - start) == A[mid]) {
        TrovaValore(A, mid + 1, end);
    } else {
        // Altrimenti il salto è a sinistra
        TrovaValore(A, start, mid - 1);
    }
}