#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

int CalcolaExp(int x, int n) {
    // Caso base: x^0 = 1
    if (n == 0) return 1;

    // Calcoliamo la potenza di x^(n/2)
    int meta = CalcolaExp(x, n / 2);

    if (n % 2 == 0) {
        // Se n è pari: (x^(n/2))^2
        return meta * meta;
    } else {
        // Se n è dispari: x * (x^(n/2))^2
        return x * meta * meta;
    }
}