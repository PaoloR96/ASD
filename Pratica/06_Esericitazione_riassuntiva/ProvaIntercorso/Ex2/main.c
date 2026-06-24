#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int T;  // Numero di casi di test
    printf("Definire il numero di casi di test: ");
    scanf("%d", &T);
    printf("\n");

    // Creiamo dinamicamente un array per memorizzare i dati dei test
    int Test[T][3]; // Ogni test ha 3 valori: S, N, P

    printf("Definire somma = S, lunghezza sequenza = N, numeri della sequenza maggiori di P:\n");
    printf("(Inserisci ogni test come: S N P separati da spazi)\n\n");

    // Lettura dei casi di test
    for (int i = 0; i < T; i++) {
        printf("Test %d: ", i + 1);
        scanf("%d %d %d", &Test[i][0], &Test[i][1], &Test[i][2]);
    }

    printf("\n================ RISULTATI =================\n\n");

    // Esecuzione dei test
    for (int i = 0; i < T; i++) {
        printf("CASO DI TEST %d\n", i + 1);
        CalcolaSequenza(Test[i][0], Test[i][1], Test[i][2]);
        printf("\n");
    }
    system("pause");
    return 0;
}
/*Per quanto riguarda la complessità e' un algoritmo di backtracking esponenziale: O(T*2^k)con T numero di test*/