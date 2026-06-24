#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // Primo albero - Esempio Completo 
    Nodo albero1[] = {
        {11, "LL", 0},
        {7,  "LLL", 0},
        {8,  "R", 0},
        {5,  "", 0},
        {4,  "L", 0},
        {13, "RL", 0},
        {2,  "LLR", 0},
        {1,  "RRR", 0},
        {4,  "RR", 0},
        {0,  "", 0} // Rappresenta () 
    };
    int count1 = sizeof(albero1) / sizeof(albero1[0]);

    // Secondo albero - Esempio "not complete" (manca radice) 
    Nodo albero2[] = {
        {3, "L", 0},
        {4, "R", 0},
        {0, "", 0} 
    };
    int count2 = sizeof(albero2) / sizeof(albero2[0]);

    // --- ELABORAZIONE ALBERO 1 ---
    printf("Sample Input 1:\n");
    stampaAlbero(albero1, count1);

    DefinisciLunghezzaNodi(albero1, count1);
    
    // Ordiniamo escludendo l'ultimo elemento () 
    qsort(albero1, count1 - 1, sizeof(Nodo), compareLivello);

    printf("Sample Output 1:\n");
    // Verifichiamo solo i nodi reali 
    if (IsCompleto(albero1, count1 - 1)) {
        // Stampa i valori n in ordine di livello 
        for (int i = 0; i < count1 - 1; i++) {
            printf("%d%s", albero1[i].n, (i == count1 - 2 ? "" : " "));
        }
        printf("\n");
    } else {
        printf("not complete\n");
    }

    printf("\n---\n");

    // --- ELABORAZIONE ALBERO 2 ---
    printf("Sample Input 2:\n");
    stampaAlbero(albero2, count2);

    DefinisciLunghezzaNodi(albero2, count2);
    qsort(albero2, count2 - 1, sizeof(Nodo), compareLivello);

    printf("Sample Output 2:\n");
    if (IsCompleto(albero2, count2 - 1)) {
        for (int i = 0; i < count2 - 1; i++) {
            printf("%d%s", albero2[i].n, (i == count2 - 2 ? "" : " "));
        }
        printf("\n");
    } else {
        printf("not complete\n"); 
    }

    system("pause");
    return 0;
}
/*
Complessità:O(n*logn)
*/