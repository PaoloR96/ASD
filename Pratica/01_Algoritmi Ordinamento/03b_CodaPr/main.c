#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int A[10];
    InitStack(A, 10);
    printf("Stack Inizializzato: ");
    StampaArray(A, 10);
    
    InsertHeap(A, 4);
    InsertHeap(A, 15);
    InsertHeap(A, 20);
    
    printf("Heap aggiornato: ");
    StampaArray(A, heap_size);
    
    printf("Massimo elemento: %d\n", HeapMax(A));
    
    int max = HeapExtractMax(A);
    printf("Massimo estratto: %d\n", max);
    
    printf("Heap dopo estrazione: ");
    StampaArray(A, heap_size);
    
    
   

    system("pause");
    return 0;
}
