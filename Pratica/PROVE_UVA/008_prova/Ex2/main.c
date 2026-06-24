#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int N_test; // Numero di casi di test 
    if (scanf("%d", &N_test) != 1) return 0;

    while (N_test--) {
        int G; // Numero di tentativi per questo caso 
        scanf("%d", &G);
        CasoTest S[G_MAX];

        for (int i = 0; i < G; i++) {
            char codiceStr[5];
            scanf("%s %d/%d", codiceStr, &S[i].x, &S[i].y);
            for (int j = 0; j < DIM; j++) {
                S[i].Segreto[j] = codiceStr[j] - '0';
            }
        }

        // Reset per ogni caso di test
        soluzioniTrovate = 0;
        int guessAttuale[DIM];

        // Avvio della ricerca ricorsiva
        CalcolaSequenza(S, G, guessAttuale, 0);

        // --- GESTIONE DELLA STAMPA FINALE --- [cite: 14]
        if (soluzioniTrovate == 0) {
            printf("impossible\n"); // Nessun codice coerente 
        } else if (soluzioniTrovate > 1) {
            printf("indeterminate\n"); // Più di un codice coerente
        } else {
            // Esattamente una soluzione coerente [cite: 16]
            for (int i = 0; i < DIM; i++) {
                printf("%d", codiceVincente[i]);
            }
            printf("\n");
        }
    }
    system("PAUSE");
    return 0;
}

/*
Complessità:$$O(B^K*G),dove:
K:il numero di cifre(4)
B:la base numerica(0-9)
G:numero di tentativi

*/