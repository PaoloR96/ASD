#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // Caso di test: n=7, k=4, m=3 
    BarCode bc = {.n = 7, .k = 4, .m = 3};
    // Stampiamo il risultato 
    printf("Risultato per BC(7, 4, 3): %d\n", CalcolaModi(bc, bc.n, bc.k));
    // testo anche il secondo caso 
    bc.m = 2;
    printf("Risultato per BC(7, 4, 2): %d\n", CalcolaModi(bc, bc.n, bc.k));
   

    system("pause");
    return 0;
}

/*
Complessità:O(m^k)
 Ad ogni passo (per ogni barra), l'algoritmo deve scegliere una larghezza i tra 1 e m
 L'albero della ricorsione ha una profondità pari a k (il numero di barre)

*/