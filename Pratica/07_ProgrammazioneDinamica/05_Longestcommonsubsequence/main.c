#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){

    char x[DIM_X+1] = "AGGTAB";
    char y[DIM_Y+1] = "GXTXAYB";

    // inizializza matrice
    InizializzaDp();

    // calcola LCS
    CalcolaLCS(x, y);

    // stampa matrice DP
    StampaDP(x, y);

    // risultato finale
    printf("\nLunghezza LCS = %d\n", DP[DIM_X][DIM_Y]);


    system("PAUSE");
    return 0;
}

/*

Ricorrenza:

    0                              se i = 0 oppure j = 0
c[i][j] = 
    c[i-1][j-1] + 1                se x[i-1] == y[j-1]
    max(c[i-1][j], c[i][j-1])      se x[i-1] != y[j-1]

Significato:
c[i][j] rappresenta la lunghezza della LCS tra:
- i primi i caratteri della stringa X
- i primi j caratteri della stringa Y

Caso base:
Se una delle due stringhe è vuota (i = 0 oppure j = 0),
la sottosequenza comune più lunga è 0.

Complessità: O(DIM_X * DIM_Y)
*/