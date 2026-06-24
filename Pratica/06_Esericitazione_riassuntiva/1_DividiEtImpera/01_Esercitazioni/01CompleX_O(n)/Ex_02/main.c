#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {

    int A[10];
    srand(time(NULL));  // Inizializza il generatore di numeri casuali

    GeneraNumeri(A, 10);

    printf("Vettore: ");
    StampaArray(A, 10);
    TrovaNumeri(A,10);
    printf("\n");



    system("pause");
    return 0;
}
