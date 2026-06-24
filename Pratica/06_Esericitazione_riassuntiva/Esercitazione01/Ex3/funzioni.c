#include <stdio.h>
#include "funzioni.h"

// Variabili globali per la miglior sottomatrice trovata
int maxArea = 0;
int bestR0 = 0, bestC0 = 0;
int bestH = 0, bestW = 0;

// ======================================================
// STAMPA MATRICE
// ======================================================
void stampaMatrice(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// ======================================================
// ESPANSIONI MASSIME DI RIGA E COLONNA
// ======================================================
int EspandiRiga(int M[N][N], int riga, int colonna) {
    int larghezza = 0;
    for (int j = colonna; j < N; j++) {
        if (M[riga][j] == 1) break;
        larghezza++;
    }
    return larghezza;
}

int EspandiColonna(int M[N][N], int riga, int colonna) {
    int altezza = 0;
    for (int i = riga; i < N; i++) {
        if (M[i][colonna] == 1) break;
        altezza++;
    }
    return altezza;
}

// ======================================================
// CONTROLLO RETTANGOLO DI SOLI ZERI
// ======================================================
int isFreeRectangle(int M[N][N], int r0, int c0, int h, int w) {
    for (int r = r0; r < r0 + h; r++)
        for (int c = c0; c < c0 + w; c++)
            if (M[r][c] == 1)
                return 0;
    return 1;
}

// ======================================================
// BACKTRACKING: esplora tutte le possibili dimensioni
// ======================================================
void BacktrackRettangolo(int M[N][N], int r0, int c0,
                         int h, int w,
                         int maxH, int maxW)
{
    // Se il rettangolo attuale non è valido, interrompe il ramo
    if (!isFreeRectangle(M, r0, c0, h, w))
        return;

    // Rettangolo valido → aggiorna massimo
    int area = h * w;
    if (area > maxArea) {
        maxArea = area;
        bestR0 = r0;
        bestC0 = c0;
        bestH = h;
        bestW = w;
    }

    // Prova tutte le altezze successive
    for (int nh = h + 1; nh <= maxH; nh++) {
        if (!isFreeRectangle(M, r0, c0, nh, w))
            break;
        BacktrackRettangolo(M, r0, c0, nh, w, maxH, maxW);
    }

    // Prova tutte le larghezze successive
    for (int nw = w + 1; nw <= maxW; nw++) {
        if (!isFreeRectangle(M, r0, c0, h, nw))
            break;
        BacktrackRettangolo(M, r0, c0, h, nw, maxH, maxW);
    }
}

// ======================================================
// AVVIA BACKTRACKING DA UNA CELLA
// ======================================================
void GeneraSottoMatrice(int M[N][N], int r0, int c0) {
    if (M[r0][c0] == 1) return;

    int maxW = EspandiRiga(M, r0, c0);
    int maxH = EspandiColonna(M, r0, c0);

    BacktrackRettangolo(M, r0, c0, 1, 1, maxH, maxW);
}

// ======================================================
// TROVA LA SOTTOMATRICE MASSIMA DI 0
// ======================================================
void TrovaSottoMatrice(int M[N][N]) {

    maxArea = 0; // reset

    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (M[r][c] == 0)
                GeneraSottoMatrice(M, r, c);

    printf("\n--- SOTTOMATRICE MASSIMA (%d celle) ---\n", maxArea);
    printf("Posizione iniziale: (%d, %d)\n", bestR0, bestC0);
    printf("Dimensioni: %d x %d\n\n", bestH, bestW);

    // Stampa della sottomatrice
    for (int r = bestR0; r < bestR0 + bestH; r++) {
        for (int c = bestC0; c < bestC0 + bestW; c++)
            printf("%d ", M[r][c]);
        printf("\n");
    }
}
