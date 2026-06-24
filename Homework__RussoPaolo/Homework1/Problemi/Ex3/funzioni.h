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
void Swap(int *a, int *b);
void StampaVettore(int arr[], int dim);
void EseguiTest(Struttura_Heap *A,int V[],int dim,int k);
/*Metodi per implementare MinHeap*/
int Parent(int i);
int Left(int i);
int Right(int i);
void MinHeapfy(Struttura_Heap *A, int i);
void BuildMinHeap(Struttura_Heap *A);
#endif
