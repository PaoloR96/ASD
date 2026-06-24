#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/*Metodi di utilità*/
void StampaVettore(int arr[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d ", arr[i]);
    }
}
void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*Metodi per implementare MinHeap*/

/*Metodi per trovare il padre e figlio sx e dx dato un indice i*/
int Parent(int i){return (i-1)/2;}
int Left(int i){return 2*i+1;}
int Right(int i){return 2*i+2;}


void MinHeapfy(Struttura_Heap *A, int i) {
    int smallest = i; // Inizializza smallest come radice
    int l = Left(i);
    int r = Right(i);
    //Controllo1: Se il figlio sinistro è nel range ed è minore del padre
    if (l < A->HeapSize && A->v[l] < A->v[smallest]) smallest = l;
    //Controllo2: Se il figlio destro è nel range ed è minore del largest attuale
    if (r < A->HeapSize && A->v[r] < A->v[smallest])smallest = r;
    // Se il più piccolo non è la radice, scambia e continua a scendere
    if (smallest != i) {
        Swap(&A->v[i], &A->v[smallest]);
        MinHeapfy(A, smallest);
    }
}

void BuildMinHeap(Struttura_Heap *A) {
    A->HeapSize = A->lenght;
    // Partiamo dall'ultimo nodo che ha almeno un figlio
    int pos = (A->lenght / 2) - 1; 
    for (int i = pos; i >= 0; i--) MinHeapfy(A, i);
}


void EseguiTest(Struttura_Heap *A,int V[],int dim,int k){
    //Passo1:Definizione variabili
    int Risultato[MAX]; // Vettore di appoggio per il risultato ordinato
    int index = 0; // Indice per riempire il vettore Risultato
    //Passo2:Imposto la dimensione iniziale dell'Heap(Se k+1 > dim ritorna dim altrimenti prendo k+1)
    A->HeapSize=(k+1<dim)?k+1 : dim;
    //Aggiorno la dimensione di A
    A->lenght = A->HeapSize;
    //Passo3: Inizializzazione e costruzione del MinHeap
    for (int i = 0; i < A->HeapSize; i++)A->v[i] = V[i];
    BuildMinHeap(A);
    // Fase 2: Scorro il resto dell'array, estraggo il minimo e inserisco il nuovo elemento ripristinando la proprietà di MinHeap
    for (int i = A->HeapSize; i < dim; i++){
        Risultato[index++]=A->v[0];//Salvo il minimo
        A->v[0]=V[i];//Inserisco il nuovo elemento nella radice
        MinHeapfy(A,0);//Ripristino l'Heap partendo sempre dalla radice 
    }
    // Passo 3: Svuoto l'Heap estraendo i minimi rimanenti
    while (A->HeapSize>0){
        Risultato[index++]=A->v[0];
        //L'ultimo elemento è all'indice HeapSize - 1
        A->v[0] = A->v[A->HeapSize-1]; // Sposto l'ultimo elemento in radice 
        A->HeapSize--;//riduco la size
        //Sec ci sono ancora elementi ripristino la proprietà di MinHeap
        if (A->HeapSize>0)MinHeapfy(A,0); 
    }
    //Passo4:Stampo il vettore ordinato
    StampaVettore(Risultato,index);
    
}
