#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void TrovaPositivi(int A[], int size) {
    int occ=ContaPositivi(A,0,size-1);
    printf("Numero maggiore di 0:%d",occ);
        
}


//variabile globale
int cont=0;
int ContaPositivi(int A[], int start, int end) {
    // Caso base: un solo elemento
    if (start == end) {
        if (A[start] > 0)
            return 1;
        else
            return 0;
    }

    // Divido il problema a metà
    int mid = (start + end) / 2;

    // Risolvo ricorsivamente le due metà
    int left  = ContaPositivi(A, start, mid);
    int right = ContaPositivi(A, mid + 1, end);

    // Combino i risultati
    return left + right;
}
