#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int T = 0, r = 0;
    int A[N];

    printf("Definisci i casi di test (max 10): ");
    scanf("%d", &T);

    if (T <= 0 || T > 10) {
        printf("Numero di casi di test non valido (1-10).\n");
        return 1;
    }

    for (int i = 0; i < T; i++) {
        printf("\nCaso di Test %d:\n", i + 1);

        // Inserimento numero di elementi con controllo 0 < r < 500
        do {
            printf("Numero di elementi (0 < r < 500): ");
            scanf("%d", &r);
            if (r <= 0 || r >= 500)
                printf("Errore: r deve essere compreso tra 1 e 499.\n");
        } while (r <= 0 || r >= 500);

        // Inserimento elementi con controllo 0 < si < 30000
        for (int j = 0; j < r; j++) {
            do {
                printf("Elemento %d (0 < si < 30000): ", j + 1);
                scanf("%d", &A[j]);
                if (A[j] <= 0 || A[j] >= 30000)
                    printf("Errore: il valore deve essere compreso tra 1 e 29999.\n");
            } while (A[j] <= 0 || A[j] >= 30000);
        }

        // Calcolo della distanza ottimale e stampa risultato
        CalcolaDistanzaOttimale(A, r);
        printf("\n");
    }

    system("pause"); // Solo Windows
    return 0;
}
