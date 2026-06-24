#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    Problema p;
    int usato[MAX_TESSERE];

    // 1. Legge n (numero spazi). Se n è 0, il programma termina 
    while (scanf("%d", &p.n) == 1 && p.n != 0) {
        
        // 2. Legge m (numero di tessere disponibili nel mazzo) 
        if (scanf("%d", &p.m) != 1) break;

        // 3. Legge la tessera iniziale (sinistra) 
        scanf("%d %d", &p.L.sinistra, &p.L.destra);

        // 4. Legge la tessera finale (destra) 
        scanf("%d %d", &p.R.sinistra, &p.R.destra);

        // 5. Legge le m tessere del mazzo
        for (int i = 0; i < p.m; i++) {
            scanf("%d %d", &p.tessere[i].sinistra, &p.tessere[i].destra);
            usato[i] = 0; // Inizializza ogni tessera come "non usata"
        }

        // 6. Avvia la ricorsione
        if (Risolvi(p, p.n, p.L.destra, usato)) {
            printf("YES\n"); // Trovata una combinazione valida 
        } else {
            printf("NO\n");  // Nessuna combinazione possibile
        }
    }
    system("pause");
    return 0;
}
/*Complessità:O(m!*2^m)*/


