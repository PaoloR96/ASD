#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   
    int array_numeri[10];
    int size=0;
    srand(time(NULL));  // Inizializza il generatore di numeri casuali

    GeneraNumeri(array_numeri, 10);

    printf("Array di numeri casuali: ");
    StampaArray(array_numeri, 10);
    size = sizeof(array_numeri)/sizeof(array_numeri[0]);

    HeapSort(array_numeri, size);
    printf("/n Array ordinato dopo HeapSort: ");
    StampaArray(array_numeri, 10);

    system("pause");
    return 0;
}
