#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int isPrimo(int n) {
    if (n <= 1) return 0;      // 0 e 1 non sono primi
    if (n == 2) return 1;      // 2 è primo
    if (n % 2 == 0) return 0;  // numeri pari > 2 non sono primi
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1; // è primo
}


void risolvi(int anello[], int usato[], int pos, int n){
        // 1. CONDIZIONE DI USCITA
        if (pos == n) {
            // Controlla l'ultimo con il primo (deve essere primo!)
            if (isPrimo(anello[pos-1] + anello[0])) StampaSoluzioni(anello, n);
            return;
        }
        // 2. TENTA OGNI NUMERO (da 2 a n)
        for (int num = 2; num <=n; num++){
            if (!usato[num]){
                if (isPrimo(anello[pos - 1] + num)) {
                        anello[pos] = num;  // Inserisci
                        usato[num] = 1;     // Segna come usato     
                        risolvi(anello,usato,pos+1,n);//vado al pos successivo
                        //BACKTRACKING: libera il numero per altri tentativi
                        usato[num] = 0;
                }
            }
        }
}

void StampaSoluzioni(int anello[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", anello[i]);
    }
    printf("\n");
}