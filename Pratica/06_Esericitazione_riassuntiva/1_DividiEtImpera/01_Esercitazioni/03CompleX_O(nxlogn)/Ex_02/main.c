#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    int A[10],N=0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("Inserisci Vettore:");
    InsNumeri(A, size);
    //printf("Stampa Vettore:");
    //StampaArray(A, size);
    printf("\n");
    printf("Definire il parametro N:");
    scanf("%d",&N);
    TrovaProdotto(A,0,size,N);

    system("pause");
    return 0;
}

/*
La complessità complessiva dell'algoritmo è O(n * log n).

- BinarySearch: complessità O(log n), perché dimezza l'intervallo ad ogni passo.

- ControllaCoppie: complessità O(n);

- TrovaProdotto: utilizza la tecnica divide-et-impera, dividendo ricorsivamente l'array in due metà fino al caso base.
  La profondità della ricorsione è O(log n), ma la somma delle complessità su tutti i livelli è O((n) * log n) ≈ O(n log n).
*/
