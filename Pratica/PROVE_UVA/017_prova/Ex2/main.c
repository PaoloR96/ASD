#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int M[N][N];
    int dim = 6; // Dimensione scacchiera 
    
    // 1. Inizializza tutta la matrice alla dimensione corretta
    InizializzaMatrice(M, dim);

    // 2. Imposta la partenza (usando indici 0-based: riga 2, colonna 2 diventa 1,1)
    Posizione pos_partenza;
    pos_partenza.r_x = 1; // Riga 2 -> indice 1
    pos_partenza.c_y = 1; // Colonna 2 -> indice 1
    
    // La posizione attuale all'inizio coincide con la partenza
    Posizione pos_attuale = pos_partenza;

    // 3. Fondamentale: segna la prima mossa e inizia il conteggio da 1 
    M[pos_partenza.r_x][pos_partenza.c_y] = 1;
    int cont = 1; 

    // 4. Avvia la ricerca
    printf("%d %d %d\n", dim, pos_partenza.r_x + 1, pos_partenza.c_y + 1);
    if (!GeneraPercorso(M, dim, pos_partenza, pos_attuale, cont)) {
        printf("No Circuit Tour.\n");
    }

    system("pause");
    return 0;
}

/*
O(8^L) con L=N^2 che rappresenta la dimensione della scacchiera
*/