#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int n = 10;
    int A[n];

    
    srand(time(NULL));
    GeneraNumeri(A, n);

    printf("Array generato: ");
    StampaArray(A, n);

    int min_diff = CalcolaMinMax(A, 0, n-1);
    printf("min(A[j]-A[i]) con i<=j: %d\n", min_diff);
    system("PAUSE");

    return 0;
}

/*
Il costo totale per un problema di dimensione $n$ è modellato dalla relazione di ricorrenza:
T(n) = 2T(n/2) + Theta(n)

Il termine 2T(n/2) riflette le due chiamate ricorsive;
il termine Theta(n) rappresenta il costo delle due scansioni lineari (TrovaMassimo e TrovaMinimo) necessarie per calcolare la differenza incrociata.
 La risoluzione tramite il Teorema Master porta alla complessità finale di O(n*log n).


*/