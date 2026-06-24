#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

#define SIZE 10   // dimensione dell'array
#define K 6       // valori casuali tra 0 e K-1

int main() {
    int arrayA[SIZE], arrayB[SIZE];
    srand(time(NULL));  // inizializza il generatore di numeri casuali

    // genera numeri casuali
    GeneraNumeri(arrayA, SIZE, K);

    printf("Array di numeri casuali: ");
    StampaArray(arrayA, SIZE);
    printf("\n");

    // ordina con Counting Sort
    CountingSort(arrayA, arrayB, SIZE, K);

    printf("\nArray ordinato: ");
    StampaArray(arrayB, SIZE);
    printf("\n");

    system("pause");
    return 0;
}