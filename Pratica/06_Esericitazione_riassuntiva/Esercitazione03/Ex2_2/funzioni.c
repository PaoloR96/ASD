#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

// Legge le spese e le converte in centesimi
void InserisciQuota(int A[], int size) {
    for (int i = 0; i < size; i++) {
        float spesa;
        scanf("%f", &spesa);
        // Convertiamo in centesimi e arrotondiamo
        A[i] = (int)(spesa * 100 + 0.5);
    }
}

int Media(int A[], int size) {
    long long somma = 0;
    for (int i = 0; i < size; i++) {
        somma += A[i];
    }
    // Arrotondiamo la media
    return (int)((somma + size / 2) / size);
}

// Calcola ricorsivamente la somma delle differenze positive
int TrovaValoreMedio(int A[], int size, int media, int index, int valMedio) {
    if (index == size) return valMedio;
    if (A[index] > media) valMedio += A[index] - media;
    return TrovaValoreMedio(A, size, media, index + 1, valMedio);
}

// Calcola e stampa la quota totale da scambiare
void CalcolaQuota(int A[], int size) {
    int media = Media(A, size);
    int valMedio = TrovaValoreMedio(A, size, media, 0, 0);
    
    // Convertiamo da centesimi a euro e stampiamo
    printf("EUR %d.%02d\n", valMedio / 100, valMedio % 100);
}