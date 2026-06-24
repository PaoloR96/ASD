#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
Sequenza leggiSequenza() {
    Sequenza s;
    s.dim = 0;
    int x;
    while (scanf("%d", &x) == 1 && x != SENTINELLA) {
        if (s.dim < MAX) s.dati[s.dim++] = x;
    }
    return s;
}

void stampaSequenza(Sequenza s) {
    for (int i = 0; i < s.dim; i++) {
        printf("%d ", s.dati[i]);
    }
    printf("\n");
}


int max4(int a, int b, int c, int d) {
    int max = a;  // partiamo dal primo numero
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}

int max3(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}


int Merge(int A[MAX], int p, int r) {
    // Caso base: se p == r, c'è un solo elemento.
    if (p == r) return A[p];
    int q = (p + r) / 2;
    //calcola ricorsivamente i massimi delle due metà
    int maxSinistra = Merge(A, p, q);
    int maxDestra = Merge(A, q + 1, r);
    //calcola il massimo che attraversa il centro usando CrossProduction
    int valMaxCross = CrossProduction(A, p, q, r);
    //restituisce il massimo tra i tre valori
    return max3(maxSinistra, maxDestra, valMaxCross);
}

int CrossProduction(int A[MAX], int p, int q, int r) {
    int MaxLeft, MinLeft, MaxRight, MinRight;
    int prodottoL = 1, prodottoR = 1;
    // 1) Trovo il MAX e MIN della catena di sinistra A[p...q]
    // Partiamo da q e andiamo a ritroso verso p per garantire la contiguità
    prodottoL = A[q];
    MaxLeft = prodottoL;
    MinLeft = prodottoL;
    for (int i = q - 1; i >= p; i--) {
        prodottoL = prodottoL * A[i];
        if (prodottoL < MinLeft)MinLeft = prodottoL;
        if (prodottoL > MaxLeft)MaxLeft = prodottoL;
    }
    // 2) Trovo il MAX e MIN della catena di destra A[q+1...r]
    // Partiamo da q+1 e andiamo verso r
    prodottoR = A[q + 1];
    MaxRight = prodottoR;
    MinRight = prodottoR;
    for (int i = q + 2; i <= r; i++) {
        prodottoR = prodottoR * A[i];
        if (prodottoR < MinRight)MinRight = prodottoR;
        if (prodottoR > MaxRight) MaxRight = prodottoR;
    }
    // Ritorno il massimo tra le 4 combinazioni possibili
    return max4(MaxLeft * MaxRight, MinLeft * MinRight, MaxLeft * MinRight, MinLeft * MaxRight);
}