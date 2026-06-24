#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int A[MAX], dim = 0, test = 0;
    // Leggo il numero di test case
    scanf("%d", &test);
    for (int i = 0; i < test; i++){
        scanf("%d", &dim);
        RiempiVettore(A, dim);
        printf("\n");
        // Stampa personalizzata per ogni caso di test
        printf("SAMPLE OUTPUT_CASO TEST %d:\n", i + 1);
        TrovaElementiMinori(A, dim);
        printf("\n");
    }
    
    system("pause");
    return 0;
}

/*
Complessità:complessita O(NlogN)
*/