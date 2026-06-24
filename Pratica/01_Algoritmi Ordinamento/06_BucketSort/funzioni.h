#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stdlib.h>

// Definizione della struttura Bucket
typedef struct Bucket {
    int* values;    // array dinamico di valori
    int count;      // numero di elementi attuali
    int capacity;   // capacità massima dell'array
} Bucket;

// Funzioni
void StampaArray(int A[], int size);
void GeneraNumeri(int A[], int size, int maxval);
void InsertionSort(int A[], int n);
void BucketSort(int A[], int size, int maxval);

#endif
