#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("Hello, World!\n");

    int array_numeri[10];
    srand(time(NULL));  // Inizializza il generatore di numeri casuali

    GeneraNumeri(array_numeri, 10);

    printf("Array di numeri casuali: ");
    StampaArray(array_numeri, 10);
    printf("\n");
    InsertSort(array_numeri,10);
    printf("Array ordinato dopo InsertSort: ");
    StampaArray(array_numeri, 10);

    system("pause");
    return 0;
}
