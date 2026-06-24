#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/* --- METODI DI UTILITÀ --- */
void EseguiTest(int arr[], int dim, const char* nome_test) {
    //Passo0:Inizializzo la mia struttura Heap V1 e V2
    Struttura_Heap H_V1, H_V2;
    H_V1.lenght = dim;
    H_V2.lenght = dim;
    //Passo1:Popoliamo entrambe le strutture
    for (int i = 0; i < dim; i++) {
        H_V1.v[i] = arr[i];
        H_V2.v[i] = arr[i];
    }

    // Passo 2: Costruiamo SOLO gli Heap, non applico l'intero HeapSort.
    // Come richiesto dalla traccia, vogliamo verificare la differenza tra le strutture generate dai due metodi di costruzione.
    BuildMaxHeap(&H_V1);
    BuildMaxHeapV2(&H_V2);    
    
    printf("\nRisultati %s:\n", nome_test);
    printf("   -> Output V1 (Classica): ");
    StampaVettore(H_V1.v, H_V1.lenght);
    printf("\n   -> Output V2 (Insert): ");
    StampaVettore(H_V2.v, H_V2.lenght);
    printf("\n");
}



void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/*Metodi per trovare il padre e figlio sx e dx dato un indice i*/
int Parent(int i){return (i-1)/2;}
int Left(int i){return 2*i+1;}
int Right(int i){return 2*i+2;}

void StampaVettore(int arr[], int dim) {
    printf("[ ");
    for (int i = 0; i < dim; i++) {
        printf("%d ", arr[i]);
    }
    printf("]");
}

/* --- VERSIONE 1: BUILD-MAX-HEAP CLASSICA --- */
void MaxHeapfy(Struttura_Heap *A, int i) {
    int largest = i; // Inizializza largest come radice
    int l = Left(i);
    int r = Right(i);
    //Controllo1: Se il figlio sinistro è nel range ed è maggiore del padre
    if (l < A->HeapSize && A->v[l] > A->v[largest]) largest = l;
    //Controllo2: Se il figlio destro è nel range ed è maggiore del largest attuale
    if (r < A->HeapSize && A->v[r] > A->v[largest])largest = r;
    // Se il più grande non è la radice, scambia e continua a scendere
    if (largest != i) {
        Swap(&A->v[i], &A->v[largest]);
        MaxHeapfy(A, largest);
    }
}
void BuildMaxHeap(Struttura_Heap *A) {
    A->HeapSize = A->lenght;
    // Partiamo dall'ultimo nodo che ha almeno un figlio
    int pos = (A->lenght / 2) - 1; 
    for (int i = pos; i >= 0; i--) MaxHeapfy(A, i);
}

/* --- VERSIONE 2: BUILD-MAX-HEAP CON INSERIMENTO --- */

void MaxHeapInsert(Struttura_Heap *A, int i) {
    //Passo1:Inzio la risalita dell'albero(NOTA:Approccio identico all'operazione di DECREASE KEY)
    while (i>0 && A->v[i]>A->v[Parent(i)]){
        // Scambia il nodo con suo padre
        Swap(&A->v[i],&A->v[Parent(i)]);
        // Aggiorna l'indice per continuare a salire
        i=Parent(i);
    }
}
void BuildMaxHeapV2(Struttura_Heap *A) {
    //Passo1:Inizialmente l'heap contiene solo il primo elemento
    A->HeapSize = 1; 
    //Passo2:Inseriamo un elemento alla volta, partendo dal secondo
    for (int i = 1; i < A->lenght; i++) {
        A->HeapSize++; // Aumentiamo la dimensione  dell'heap
        MaxHeapInsert(A, i); // Facciamo salire il nuovo elemento se necessario
    }
}

