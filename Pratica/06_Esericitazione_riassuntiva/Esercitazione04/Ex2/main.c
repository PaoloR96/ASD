#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

#define MAX_TEST 65
#define MAX_NQ 10000

static int A[MAX_TEST][MAX_NQ];    // biglie
static int K[MAX_TEST][MAX_NQ];    // query
static int NQ[MAX_TEST][2];        // N e Q

int main() {
    int dimIns = 0;
    // --- Lettura dei casi ---
    while (1) {
        int N, Q;
        printf("Definire N e Q:\n");
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0)break;
        NQ[dimIns][0] = N;
        NQ[dimIns][1] = Q;
        // --- Lettura biglie ---
        printf("Inserire %d biglie:\n", N);
        InserimentoElementi(A[dimIns], N);
        // --- Lettura query ---
        printf("Inserire %d query:\n", Q);
        InserimentoElementi(K[dimIns], Q);
        dimIns++;
        if (dimIns >= MAX_TEST) break;
    }

    // --- Elaborazione e output ---
    for (int c = 0; c < dimIns; c++) {
        InsertSort(A[c], NQ[c][0]);
        printf("CASE# %d:\n", c + 1);
        for (int i = 0; i < NQ[c][1]; i++) {
            int key = K[c][i];
            int pos = RicercaBinaria(A[c], 0, NQ[c][0] - 1, key);
            if (pos != -1) {
                while (pos > 0 && A[c][pos - 1] == key)
                    pos--;
                printf("%d found at %d\n", key, pos + 1);
            } else {
                printf("%d not found\n", key);
            }
        }
    }

    system("pause");
    return 0;
}
/*l programma, per ogni caso di test, ordina le biglie usando Insertion Sort, che richiede un tempo pari a O(N²) nel caso peggiore.
Successivamente esegue le richieste (query) tramite ricerca binaria, che funziona in O(log N) per ogni ricerca.
Se ci sono Q query, il costo totale della fase di ricerca è O(Q log N)
T(N)=O(N² + Q log N)

*/