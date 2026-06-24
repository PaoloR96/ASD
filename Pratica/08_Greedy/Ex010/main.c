#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    unsigned int n, l, u;
    
    // Legge N, L e U fino alla fine del file (EOF)
    while (scanf("%u %u %u", &n, &l, &u) != EOF) {
        risolvi_mask(n, l, u);
    }
   
    system("pause");
    return 0;
}
/*Complessità:O(N)*/