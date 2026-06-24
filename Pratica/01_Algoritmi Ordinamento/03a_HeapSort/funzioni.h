#ifndef FUNZIONI_H
#define FUNZIONI_H

// Prototipi delle funzioni
void StampaArray(int A[], int size);
void GeneraNumeri(int A[], int size);
/*Prototipi funzione HeapSort*/
int left(int i);
int right(int i);
void swap(int *a,int *b);
// Ripristina la proprietà di max-heap a partire dall'indice i
void MaxHeapify(int A[], int i, int size);
// Costruisce un max-heap dall'array A
void BuildMaxHeap(int A[], int size);
// Ordina l'array A usando HeapSort
void HeapSort(int A[], int size);
#endif
