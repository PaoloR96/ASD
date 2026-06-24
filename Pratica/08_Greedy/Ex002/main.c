#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int M = 10; // Obiettivo: coprire da 0 a 10 
    
    // Valori precaricati 
    Punto segmenti[] = {
        {-1, 2},
        {0, 4},
        {2, 6},
        {5, 11},
        {3, 10},
        {8, 12}
    };
    
    int n = sizeof(segmenti) / sizeof(segmenti[0]);

    // 1. L'ordinamento è OBBLIGATORIO per la logica greedy 
    qsort(segmenti, n, sizeof(Punto), comparaPunti);

    printf("--- Risultato per M = %d ---\n", M);
    TrovaSegmentoM(segmenti, n, M);
   

    system("pause");
    return 0;
}

/*Complessità:O(n*logn)*/