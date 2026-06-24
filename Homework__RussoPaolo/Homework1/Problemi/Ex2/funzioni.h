#ifndef FUNZIONI_H
#define FUNZIONI_H
#define MAX 100
/*Definisco la mia struttura Heap*/
typedef struct{
    int HeapSize;
    int lenght; 
    int v[MAX];
} Struttura_Heap;

/* Metodi di utilità */
int Parent(int i);
int Left(int i);
int Right(int i);
void Swap(int *a, int *b);
void StampaVettore(int arr[], int dim);
void EseguiTest(int arr[], int dim, const char* nome_test);
/* Metodi Heap classici (V1) */
void MaxHeapfy(Struttura_Heap *A, int i);
void BuildMaxHeap(Struttura_Heap *A);
/* Metodi Heap V2 (con inserimento) */
void MaxHeapInsert(Struttura_Heap *A, int i);
void BuildMaxHeapV2(Struttura_Heap *A);

#endif