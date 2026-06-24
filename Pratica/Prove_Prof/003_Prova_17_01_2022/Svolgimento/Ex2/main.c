#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int numPile = 3; // Numero di pile di test
    NumeroFlip ris[3]; 
    int dim = 5; // Dimensione fissa per il Sample

    for (int i = 0; i < numPile; i++) {
        // Riempio il vettore e lo salvo anche nella struct per l'output
        for (int j = 0; j < dim; j++) scanf("%d", &ris[i].Vettore[j] );
        // Calcolo la sequenza di flip e la salvo
        ris[i] = CalcolaNumeroFlip(ris[i].Vettore, dim); 
    }
    
    printf("\nSAMPLE OUTPUT: \n");
    for (int i = 0; i < numPile; i++) {
        // Stampo la pila originale
        for (int j = 0; j < dim; j++) printf("%d ", ris[i].Vettore[j]);
        
        printf("\n");

        // Stampo la sequenza di flip salvata in F fino allo 0
        int k = 0;
        do {
            printf("%d ", ris[i].F[k]);
        } while (ris[i].F[k++] != 0);
        printf("\n");
    }

    system("pause");
    return 0;
}

/*Complessità: O(n^2)*/