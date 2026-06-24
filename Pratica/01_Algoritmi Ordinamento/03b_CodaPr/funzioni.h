#ifndef FUNZIONI_H
#define FUNZIONI_H
/* Variabile globale per la dimensione dell’heap */
extern int heap_size;
/* Prototipi delle funzioni*/
void StampaArray(int A[], int size);
/* Prototipi STACK*/
void Swap(int*a,int*b);
//Metodi Heap
int Parent(int i);
int left(int i);
int right(int i);
void MaxHeapify(int A[], int i, int size);
//Operazioni sullo stack
void InitStack(int A[], int size);
void InsertHeap(int A[], int key);
void HeapIncreaseKey(int A[], int i, int key);
int HeapMax(int A[]);
int HeapExtractMax(int A[]);
#endif
