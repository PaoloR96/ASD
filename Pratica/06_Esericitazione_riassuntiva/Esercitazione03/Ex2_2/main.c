#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        int spese[1000];  // Array per le spese in centesimi
        InserisciQuota(spese, n);
        CalcolaQuota(spese, n);
    }
    system("pause");
    return 0;
}

/*Complessità O(N)*/
