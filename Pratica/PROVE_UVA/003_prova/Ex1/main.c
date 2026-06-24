#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Punto P[] = {{0, 2},{6, 67},{43, 71},{39, 107},{189, 140}};
    int n = sizeof(P) / sizeof(P[0]);
    //1.Ordino in base alla coordinata x
    qsort(P, n, sizeof(Punto), cmpPuntoX);
   // 3. Salviamo il risultato della funzione in una variabile
    double risultato = risolvi(P, 0, n - 1);
    if (risultato >= 10000.0) {
        printf("INFINITY\n");
    } else {
    printf("%.4f\n", risultato);
    }
    system("pause");
    return 0;
}