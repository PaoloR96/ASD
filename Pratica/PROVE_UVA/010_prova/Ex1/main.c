#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    long long valore;
    long long sequenza[MAX_SEQ];
    int contatore = 0;

    // Legge dinamicamente dallo standard input 
    while (scanf("%lld", &valore) != EOF) {
        if (valore == -999999) { // Sentinella di fine sequenza 
            if (contatore > 0) {
                Risultato finale = DividiSequenza(sequenza, 0, contatore - 1);
                printf("%lld\n", finale.maxVal); // Output su riga differente 
                contatore = 0;
            }
        } else {
            if (contatore < MAX_SEQ) {
                sequenza[contatore++] = valore; // Massimo 100 numeri 
            }
        }
    }
    system("pause");
    return 0;
}

/*Complessità:O(n*logn)*/
