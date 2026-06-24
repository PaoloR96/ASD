#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // 1. Precaricamento statico dei dati del test [cite: 19, 20, 21, 22, 23, 24]
    int N = 5; 
    Punto p[N_MAX] = {
        {0, 2},
        {6, 67},
        {43, 71},
        {39, 107},
        {189, 140}
    };

    // 2. Ordinamento obbligatorio per X 
    qsort(p, N, sizeof(Punto), comparaX);

    // 3. Esecuzione dell'algoritmo
    double risultato = CalcolaSequenza(p, 0, N - 1);

    // 4. Controllo del limite INFINITY
    if (risultato >= 10000.0) {
        printf("INFINITY\n");
    } else {
        // Output con 4 cifre decimali come richiesto 
        printf("%.4f\n", risultato);
    }

    system("pause");
    return 0;
}

/*Complessità:O(N*log*N)*/