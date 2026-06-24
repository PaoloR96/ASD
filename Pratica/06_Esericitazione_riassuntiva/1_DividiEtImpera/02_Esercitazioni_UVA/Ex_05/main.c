#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include la funzione solve definita in funzioni.c



int main() {
    double test_cases[MAX_TESTS][6]; 
    int n = 0; // numero di casi letti

    printf("Inserisci i casi di test (fino a EOF):\n");

    // Legge tutti i casi di test fino a EOF
    while (scanf("%lf %lf %lf %lf %lf %lf", 
                 &test_cases[n][0], &test_cases[n][1], &test_cases[n][2], 
                 &test_cases[n][3], &test_cases[n][4], &test_cases[n][5]) == 6) {
        n++;
        if (n >= MAX_TESTS) {
            printf("Raggiunto il numero massimo di casi.\n");
            break;
        }
    }

    printf("Sample Output\n");
    CalcolaFunzione(test_cases,n);

    system("PAUSE");

    return 0;
}

/*
 * Complessità:
 * - Per ogni caso di test applichiamo la bisezione.
 * - Il metodo di bisezione ha complessità O(log M),
 *   dove M è la dimensione dell'intervallo iniziale / precisione richiesta.
 *
 * Poiché l'intervallo è [0, 1] e la precisione è eps ≈ 1e-7,
 * servono circa log2(10^7) ≈ 23 iterazioni.
 *
 * Quindi per T casi di test:
 *
 *     T(n) = O(T * log(1/eps))
 *
 * Poiché log(1/eps) è costante per questo problema,
 * l’intero algoritmo è O(T).
 */
