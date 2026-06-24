#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int T = 0, i = 1;  // T = numero di casi di test, i = contatore
    printf("Definire il numero di casi di test: ");
    scanf("%d", &T);

    // ripeti per ogni caso di test
    do {
        printf("\n--- Inserimento caso di test %d ---\n", i);

        int k, n;
        printf("Inserisci K e la dimensione dell' array: ");
        scanf("%d %d", &k, &n);

        // creo un array abbastanza grande (K, N + dati)
        int size = n + 2;
        int A[size];
        A[0] = k;
        A[1] = n;

        printf("Inserisci %d elementi dell'array:\n", n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[j + 2]);
        }

        CalcolaOccorenze(A, size);

        i++;
        T--;

    } while (T != 0);

    system("pause");
    return 0;
}
/*
Applichiamo il Teorema Master,T(n)=aT(n/b)+O(n^c),ho:
*a = 2 (due chiamate)
*b = 2 (si divide a metà)
*c = 0 (il lavoro fuori dalla ricorsione è costante)

n^(log(b​))a=n^log2(​2))=n^1 ===>=O(n)


*/