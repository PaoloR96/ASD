#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
int heap_size = 0;
void StampaArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
/*Metodi stack*/
void InitStack(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = 0;
    }
}

int Parent(int i) {return (i - 1) / 2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}

void Swap(int*a,int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void MaxHeapify(int A[], int i, int size) {
    int massimo = i;
    int l = left(i);
    int r = right(i);

    if (l < size && A[l] > A[massimo]) massimo = l;
    if (r < size && A[r] > A[massimo]) massimo = r;

    if (massimo != i) {
        Swap(&A[i], &A[massimo]);
        MaxHeapify(A, massimo, size);
    }
}


void HeapIncreaseKey(int A[], int i, int key) {
    if (key < A[i]) {
        printf("Errore: nuova chiave minore della corrente.\n");
        return;
    }
    A[i] = key;
    while (i > 0 && A[Parent(i)] < A[i]) {
        Swap(&A[i], &A[Parent(i)]);
        i = Parent(i);
    }
}


void InsertHeap(int A[], int key) {
    A[heap_size] = INT_MIN;   // inizializza con valore minimo
    HeapIncreaseKey(A, heap_size, key);
    heap_size++;
}
int HeapMax(int A[]) {
    if (heap_size < 1) {
        printf("Errore: heap vuoto!\n");
        return INT_MIN;
    }
    return A[0];
}

int HeapExtractMax(int A[]){
    if (heap_size < 1) {
        printf("Errore: heap underflow\n");
        return INT_MIN;
    }
   int max = A[0];                    // il massimo è la radice
    A[0] = A[heap_size - 1];           // sposto l'ultimo elemento in cima
    heap_size--;                        // riduco la dimensione dell'heap
    MaxHeapify(A, 0, heap_size);       // ripristino la proprietà max-heap dalla radice
    return max;
}


   