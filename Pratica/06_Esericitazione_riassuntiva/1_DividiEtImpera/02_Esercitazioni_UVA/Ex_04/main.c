#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int N, Q;
    int scimmie[SIZE];
    int query[SIZE];
    printf("SAMPLE INPUT:\n");
    // Lettura input
    scanf("%d", &N);
    RiempiVettore(scimmie, N);

    scanf("%d", &Q);
    RiempiVettore(query, Q);
    printf("SAMPLE OUTPUT:\n");
    // Elaborazione e stampa output
    TrovaValori(scimmie, N, query, Q);
    system("pause");
    return 0;
}
/*
Analisi della complessità:

- Per ogni query:
    - Eseguo LowerBound → O(log N)
    - Eseguo UpperBound → O(log N)
  Quindi T(query) = O(log N) + O(log N) = O(log N)

- Avendo Q query indipendenti:
    T(totale) = Q * O(log N) = O(Q * log N)
*/



