#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // n = numero di elementi, q = numero di query
    int n = 10, q = 3;
    // Array ordinato a
    int a[10] = {-1, -1, 1, 1, 1, 1, 3, 10, 10, 10};
    // Query (i, j)
    int queries[3][2] = {
        {2, 3},
        {1, 10},
        {5, 10}
    };
    //vettore delle frequenze
    int Freq[10] = {0};
    // 1. Analizziamo l'array a per mappare frequenze e blocchi
    CreaVettoreOccorrenze(Freq, a, n);
    // 2. Eseguiamo le query
    printf("Risultati delle query:\n");
    for (int k = 0; k < q; k++) {
        // Prendiamo gli indici i e j dalla matrice queries 
        int i = queries[k][0];
        int j = queries[k][1];

        // Passiamo i indici convertiti in 0-based (i-1, j-1) alla funzione 
        int risultato = TrovaOccorenze(Freq, a, i - 1, j - 1, n);
        
        printf("Query %d (%d, %d): %d\n", k + 1, i, j, risultato);
    }
   

    system("pause");
    return 0;
}
/*Complessità: O(n*logn)
*/