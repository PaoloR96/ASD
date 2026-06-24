#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"

// Funzione per leggere un vettore
void RiempiVettore(int A[], int size) {
    for (int i = 0; i < size; i++)
        scanf("%d", &A[i]);
}

// Ricerca ricorsiva: primo elemento > q
int UpperBound(int A[], int q, int low, int high) {
    if (low == high) return low;

    int mid = (low + high) / 2;

    if (A[mid] <= q)
        return UpperBound(A, q, mid + 1, high);
    else
        return UpperBound(A, q, low, mid);
}

// Ricerca ricorsiva: primo elemento >= q
int LowerBound(int A[], int q, int low, int high) {
    if (low == high) return low;

    int mid = (low + high) / 2;

    if (A[mid] < q)
        return LowerBound(A, q, mid + 1, high);
    else
        return LowerBound(A, q, low, mid);
}

// Trova e stampa predecessore e successore per ogni query
void TrovaValori(int scimmie[], int N, int query[], int Q) {
    for (int i = 0; i < Q; i++) {
        int x = query[i];

        int lb = LowerBound(scimmie, x, 0, N);
        int ub = UpperBound(scimmie, x, 0, N);

        // Predecessore (più alta più bassa)
        if (lb == 0)
            printf("X ");
        else
            printf("%d ", scimmie[lb - 1]);

        // Successore (più bassa più alta)
        if (ub == N)
            printf("X\n");
        else
            printf("%d\n", scimmie[ub]);
    }
}