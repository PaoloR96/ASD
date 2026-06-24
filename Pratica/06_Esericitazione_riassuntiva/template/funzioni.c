#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void GeneraNumeri(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 101;
    }
}
