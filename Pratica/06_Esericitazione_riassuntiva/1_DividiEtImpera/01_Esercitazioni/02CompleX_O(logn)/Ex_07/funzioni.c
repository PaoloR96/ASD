#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Funzione per riempire un array
void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("A[%d]:",i+1);
        scanf("%d", &A[i]);
    }
}
int TrovaPosizioneX(int A[], int start, int end, int pos, int x) {
    /* condizione di uscita */
    if(start > end) return pos;
    int mid = (start + end) / 2;
    if(A[mid] == x) pos = mid;
    /* se x può trovarsi a destra → cerca a destra */
    if(A[mid] <= x)
        pos = TrovaPosizioneX(A, mid + 1, end, pos, x);

    /* se x può trovarsi a sinistra → cerca a sinistra */
    if(A[mid] >= x)
        pos = TrovaPosizioneX(A, start, mid - 1, pos, x);

    return pos;
}

