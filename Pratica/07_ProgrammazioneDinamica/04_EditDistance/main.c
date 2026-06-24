#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){
    char x[DIM_X] = "alghoritm";
    char y[DIM_Y] = "altruistic";
    InizializzaDp();
    EditDistance(x, y);
    StampaDP(x, y);

    printf("\nEdit distance minima: %d\n", DP[DIM_X][DIM_Y]);
    




    system("PAUSE");
    return 0;
}


/*

==============================
EDIT DISTANCE - DESCRIZIONE
==============================

1. Complessità temporale e spaziale

- La matrice DP ha dimensione (DIM_X+1) x (DIM_Y+1), quindi ci sono
  (DIM_X+1)*(DIM_Y+1) celle da calcolare.

- Ogni cella richiede un'operazione di minimo tra 3 valori:
    1) Delete
    2) Insert
    3) Replace / Copy

- Complessità totale è:O(DIM_X * DIM_Y)

---

2. Definizione ricorsiva dell’edit distance

Sia x[0..n-1] e y[0..m-1] le due stringhe da confrontare.
Definiamo DP(i,j) come il costo minimo per trasformare
i primi i caratteri di x nei primi j caratteri di y.

Caso base:
    DP(0,0) = 0                 // entrambe le stringhe vuote
    DP(i,0) = i                 // eliminazioni necessarie
    DP(0,j) = j                 // inserimenti necessari

Caso ricorsivo:
    Per i > 0 e j > 0:
    
    DP(i,j) = min(
        DP(i-1,j) + 1,                  // delete x[i-1]
        DP(i,j-1) + 1,                  // insert y[j-1]
        DP(i-1,j-1) + costo_replace     // replace o copy
    )
    
    dove costo_replace = 0 se x[i-1] == y[j-1] (copy),
                         1 se x[i-1] != y[j-1] (replace)

---




*/