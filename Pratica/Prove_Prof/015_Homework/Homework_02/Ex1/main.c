#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

int main() {
    printf("SAMPLE INPUT:\n");
    Node *ListaNodi = NULL;
    // Un array di 6 elementi (quindi 2n = 6, n = 3)
    int A[] = {1, 2, 3, 4, 5, 6}; 
    int dim = sizeof(A) / sizeof(A[0]);
    ListaNodi = CreaListaNodi(A, dim);
    StampaLista(ListaNodi);
    printf("\nSAMPLE OUTPUT:\n");
    InvertiLista(ListaNodi); 
    // Il risultato atteso è: 1, 2, 3, 6, 5, 4
    StampaLista(ListaNodi);
    system("pause");
    return 0;
}
/*Complessità :O(N)*/