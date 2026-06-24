#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // opzionale

void StampaCombinazioni(int S[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("]\n");
}

void BackTracking(int S[], int s[], int n, int pos, int start, int target, int somma) {
    // Caso base: somma esatta
    if (somma == target) {
        StampaCombinazioni(s, pos);
        return;
    }

    // Caso base: superato target → interrompi
    if (somma > target) return;

    // Esplora gli elementi successivi
    for (int i = start; i < n; i++) {
        s[pos] = S[i];
        BackTracking(S, s, n, pos + 1, i + 1, target, somma + S[i]);
    }
}

void GeneraCombinazioni(int S[], int n, int target) {
    int s[n];
    BackTracking(S, s, n, 0, 0, target, 0);
}
