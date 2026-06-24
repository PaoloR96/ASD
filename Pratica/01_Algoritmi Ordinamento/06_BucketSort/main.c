#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"

#define SIZE 10
#define MAXVAL 100

int main() {
    int array[SIZE];
    srand(time(NULL));

    GeneraNumeri(array, SIZE, MAXVAL);

    printf("Array di numeri casuali: ");
    StampaArray(array, SIZE);

    BucketSort(array, SIZE, MAXVAL);

    printf("\nArray ordinato: ");
    StampaArray(array, SIZE);

    system("pause");
    return 0;
}
