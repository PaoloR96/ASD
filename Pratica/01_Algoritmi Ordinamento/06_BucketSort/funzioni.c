#include <stdio.h>
#include "funzioni.h"

// Stampa array
void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Genera numeri casuali
void GeneraNumeri(int A[], int size, int maxval) {
    for (int i = 0; i < size; i++)
        A[i] = rand() % maxval;
}

// Insertion Sort per ordinare ogni bucket
void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Bucket Sort
void BucketSort(int A[], int size, int maxval) {
    int i, j;

    // 1)Creazione dei bucket
    // Allocazione dinamica di un array di bucket di dimensione "size"
    Bucket* buckets = malloc(sizeof(Bucket) * size);
    for (i = 0; i < size; i++) {
        buckets[i].count = 0;                     // inizialmente nessun elemento
        buckets[i].capacity = 5;                  // capacità iniziale dell'array interno
        buckets[i].values = malloc(sizeof(int) * buckets[i].capacity);  // allocazione dinamica dei valori
    }

    // 2)Distribuzione degli elementi nei bucket
    for (i = 0; i < size; i++) {
        // Calcolo dell'indice del bucket
        // Valori più piccoli finiscono nei bucket iniziali
        // Valori grandi finiscono nei bucket finali
        int idx = (A[i] * size) / (maxval + 1);
        Bucket* b = &buckets[idx];  // puntatore al bucket corretto

        // Se il bucket è pieno, raddoppiamo la capacità
        if (b->count == b->capacity) {
            b->capacity *= 2;
            int* temp = realloc(b->values, sizeof(int) * b->capacity);
            if (temp == NULL) {  // controllo allocazione
                printf("Errore allocazione memoria!\n");
                exit(1);
            }
            b->values = temp;
        }

        // Inseriamo l'elemento nel bucket e incrementiamo il contatore
        b->values[b->count++] = A[i];
    }

    // 3)Ordinamento dei bucket e ricostruzione dell'array
    int pos = 0;  // posizione corrente nell'array originale
    for (i = 0; i < size; i++) {
        // Ordiniamo il singolo bucket con Insertion Sort
        InsertionSort(buckets[i].values, buckets[i].count);

        // Copiamo tutti gli elementi ordinati del bucket nell'array originale
        for (j = 0; j < buckets[i].count; j++)
            A[pos++] = buckets[i].values[j];

        // Liberiamo la memoria del bucket
        free(buckets[i].values);
    }

    // Liberiamo la memoria dell'array di bucket
    free(buckets);
}