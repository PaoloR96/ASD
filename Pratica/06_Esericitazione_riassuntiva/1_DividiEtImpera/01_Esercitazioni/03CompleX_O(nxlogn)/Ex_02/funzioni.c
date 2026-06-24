#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d",&A[i]); 
    }
}
int BinarySearch(int A[], int left, int right, int val) {
    // Condizione di uscita: se l'intervallo è vuoto, il valore non è presente
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (A[mid] == val) return mid;
    // Se il valore è maggiore dell'elemento centrale,
    // cerca nella metà destra dell'array
    if (A[mid] < val)
        return BinarySearch(A, mid + 1, right, val);
    else
        // Altrimenti, cerca nella metà sinistra dell'array
        return BinarySearch(A, left, mid - 1, val);
}




// Controlla tutte le coppie tra l'intervallo [startA..endA] e [startB..endB]
void ControllaCoppie(int A[], int startA, int endA, int startB, int endB, int N) {
    for (int i = startA; i <= endA; i++) {
        if (N % A[i] == 0) {
            int val = N / A[i];
            int idx = BinarySearch(A, startB, endB, val);
            if (idx != -1) {
                printf("Trovati indici: i=%d, j=%d -> %d * %d = %d\n", i, idx, A[i], A[idx], N);
            }
        }
    }
}

// Funzione ricorsiva divide-et-impera per trovare prodotti
void TrovaProdotto(int A[], int start, int end, int N) {
    if (start >= end) return; // caso base: 0 o 1 elemento

    int mid = (start + end) / 2;

    // Controlla coppie tra metà sinistra e metà destra
    ControllaCoppie(A, start, mid, mid + 1, end, N);

    // Ricorsione sulle due metà
    TrovaProdotto(A, start, mid, N);
    TrovaProdotto(A, mid + 1, end, N);
}