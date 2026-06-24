#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
        int elenco_edifici[MAX_EDIFICI][3];
        int n = 0;
        // Lettura delle triple (L, H, R)
        printf("SAMPLE INPUT:\n");
        while (scanf("%d %d %d", &elenco_edifici[n][0], &elenco_edifici[n][1], &elenco_edifici[n][2]) == 3)n++;
        if (n == 0) return 0;
        Punto skyline_finale[MAX_PUNTI];
        // Avvio della risoluzione dividi et impera
        int totale_punti = risolvi(elenco_edifici, 0, n - 1, skyline_finale);
        printf("SAMPLE OUTPUT:\n");
        // Stampa del vettore skyline finale
        for (int i = 0; i < totale_punti; i++) {
            printf("%d %d", skyline_finale[i].x, skyline_finale[i].h);
            if (i < totale_punti - 1) printf(" ");
        }
        printf("\n");
        system("pause");
        return 0;
}
/*Complessità: O(n*logn)*/