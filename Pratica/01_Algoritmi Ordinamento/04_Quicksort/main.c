#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   
    int array_numeri[10];
    srand(time(NULL));  // Inizializza il generatore di numeri casuali

    GeneraNumeri(array_numeri, 10);

    printf("Array di numeri casuali: ");
    StampaArray(array_numeri, 10);
    printf("\n");
    Quicksort(array_numeri,0,9);
    printf("Array di numeri ordinati con QuickSort: ");
    StampaArray(array_numeri, 10);


    system("pause");
    return 0;
}
