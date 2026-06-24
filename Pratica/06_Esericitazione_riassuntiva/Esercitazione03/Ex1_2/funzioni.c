#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiMatrice(int A[][2], int size) {
    for (int i = 0; i < size; i++) scanf("%d %d", &A[i][0], &A[i][1]); 
}

void CalcolaResidui(float R[], int A[][2], int size) {
    for (int i = 0; i < size; i++) {
        int T = A[i][0];
        int S = A[i][1];
        R[i] = (float)S / (float)T; 
    }
}
void StampaOrdine(int ordine[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ordine[i]);
    }
    printf("\n");
}

void OrdinaLavori(int ordine[], float R[], int size) {

    // Inizializzo l'array degli indici: 1,2,3,...,size
    for (int i = 0; i < size; i++) {
        ordine[i] = i + 1;
    }

    // Bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {

            int idx1 = ordine[j] - 1;     // converto da indice lavoro → indice array
            int idx2 = ordine[j+1] - 1;

            if (R[idx1] < R[idx2]) {
                // scambia ordine[j] con ordine[j+1]
                int temp = ordine[j];
                ordine[j] = ordine[j+1];
                ordine[j+1] = temp;
            }
        }
    }
}