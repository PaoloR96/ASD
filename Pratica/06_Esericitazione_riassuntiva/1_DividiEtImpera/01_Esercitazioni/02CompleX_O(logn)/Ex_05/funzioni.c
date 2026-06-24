#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) scanf("%d",&A[i]);
}
int TrovaMinRelativo(int A[], int start, int end) {
    /* caso base: se c'è un solo elemento, è minimo relativo */
    if (start == end)
        return start;
    
    /*caso ricorsivo*/
        int mid = (start + end) / 2;
    /* controlli per il bordo sinistro */
    if (mid == 0 || A[mid] <= A[mid - 1]) {
        /* controlli per il bordo destro */
        if (mid == end || A[mid] <= A[mid + 1])return mid;   // minimo relativo trovato
    }

    /* se il vicino sinistro è minore, il minimo relativo è a sinistra */
    if (mid > 0 && A[mid] > A[mid - 1])
        return TrovaMinRelativo(A, start, mid - 1);

    /* altrimenti è a destra */
    return TrovaMinRelativo(A, mid + 1, end);
}
