#include <stdio.h>
#include "funzioni.h"

void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
}

void DefinisciIntervallo(int ij[][2], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &ij[i][0], &ij[i][1]);
    }
}
