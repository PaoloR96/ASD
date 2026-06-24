#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int n, caso = 1;
    // Legge n finché il file non finisce 
    while (scanf("%d", &n) != EOF) {
        // Stampa il numero del caso 
        printf("Case %d:\n", caso++);

        int usato[20] = {0}; // DIM sufficiente per n <= 16 
        int anello[20];

        // Il primo numero deve essere sempre 1 
        anello[0] = 1;
        usato[1] = 1;

        // Avvia il backtracking dalla posizione 1
        risolvi(anello, usato, 1, n);
    }
   

    system("pause");
    return 0;
}
/*Complessità :O(N-1!)
Il problema ti chiede di disporre n numeri in un anello. 
Poiché il primo numero è fisso (1), devi decidere come disporre i restanti n-1 numeri. 
Per il secondo posto hai n-1 scelte. 
Per il terzo posto hai n-2 scelte. E così via.

*/