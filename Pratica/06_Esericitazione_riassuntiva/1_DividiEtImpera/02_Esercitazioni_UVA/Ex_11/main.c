#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {

    int A[SIZE][SIZE];   // vettori
    int ij[SIZE][2];     // intervalli
    int n[SIZE], q[SIZE];
    int index = 0;

    while (1) {
        // leggi n
        scanf("%d", &n[index]);

        // condizione di terminazione
        if (n[index] == 0)
            break;

        // leggi q
        scanf("%d", &q[index]);

        // leggi i n valori
        RiempiVettore(A[index], n[index]);

        // leggi i q intervalli
        DefinisciIntervallo(&ij[index], q[index]);

        index++;
    }
     system("pause");
    return 0;
}

