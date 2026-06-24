#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int C[] = {10,30,5,60,2};
    int n=4;
    //Inizializza DP[i][j]
    InizializzaDp(DP, n);
    //Applico il calcolo della parentesizzazione 
    matrixChain(C,n);
    // Stampa tabella
    stampaDP(DP, n);
    printf("\n");
    printf("\nCosto minimo: %d\n",DP[1][n]);
    printf("\nParentesizzazione ottima:\n");
    stampaParentesi(S,1,n);
    printf("\n");




    system("PAUSE");
    return 0;
}


/*

Ricorrenza:

DP[i,j] = 
    0                                se i == j
    min_{i <= k < j} { DP[i,k] + DP[k+1,j] + C[i-1]*C[k]*C[j] }  se i < j

Dove:
- DP[i,j] = costo minimo per moltiplicare matrici da A_i a A_j
- C[] = vettore dimensioni matrici, C[i-1]*C[k]*C[j] = costo moltiplicazione tra i due sottoproblemi

Complessità:

- Tre cicli annidati: lunghezza catena diag, indice iniziale i, posizione split k
- Ogni ciclo può arrivare a n iterazioni
- Complessità totale: O(n^3)



*/