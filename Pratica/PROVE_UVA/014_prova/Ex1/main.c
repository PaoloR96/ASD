#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int test_cases;
    
    // Legge il numero di casi di test 
    if (scanf("%d", &test_cases) != 1) return 0;

    while (test_cases--) {
        // Reset della matrice per ogni nuovo caso
        for (int i = 0; i < DIM; i++)
            for (int j = 0; j < DIM; j++)
                mappa[i][j] = 0;

        // Elabora la prima stringa del test case 
        scanf("%s", stringa);
        indice = 0;
        elabora_quadtree(0, 0, DIM);

        // Elabora la seconda stringa sopra la stessa matrice (unione logica)
        scanf("%s", stringa);
        indice = 0;
        elabora_quadtree(0, 0, DIM);

        // Conta quanti pixel sono neri (valore 1)
        int conteggio_neri = 0;
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                if (mappa[i][j] == 1) {
                    conteggio_neri++;
                }
            }
        }

        // Stampa il risultato finale 
        printf("There are %d black pixels.\n", conteggio_neri);
    }
    system("pause");
    return 0;
} 



/*Complessità:O(n)*/
