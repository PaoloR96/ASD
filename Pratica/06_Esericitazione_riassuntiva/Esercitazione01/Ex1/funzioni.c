#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

#define N 5

int index = 0;  // globale: conta quanti percorsi trovati

void StampaLabirinto(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void TrovaPercorso(int M[N][N], int visitato[N][N], int percorso[N * N], int riga, int colonna, int pos) {
    /* Controlli */
    if (riga < 0 || riga >= N || colonna < 0 || colonna >= N ||M[riga][colonna] == 0 || visitato[riga][colonna] == 1)return;
    // Controllo muro, cella vietata o già visitata
    if (CellaVietata(M, riga, colonna) || visitato[riga][colonna] == 1)return;
    pos++;
    /* Caso base: uscita */
    if (riga == N - 1 && colonna == N - 1) {
        percorso[index] = pos;
        index++;
        return;
    }
    visitato[riga][colonna] = 1;
    /* Quattro direzioni */
    TrovaPercorso(M, visitato, percorso, riga, colonna + 1, pos); // destra
    TrovaPercorso(M, visitato, percorso, riga, colonna - 1, pos); // sinistra
    TrovaPercorso(M, visitato, percorso, riga + 1, colonna, pos); // giù
    TrovaPercorso(M, visitato, percorso, riga - 1, colonna, pos); // su
    visitato[riga][colonna] = 0; // backtracking
}


int CellaVietata(int M[N][N], int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N)return 1; // fuori dal labirinto
    // se la cella è 0 → vietata
    if (M[r][c] == 0)return 1;

    // se una cella adiacente è 0 → vietata
    if (r > 0 && M[r - 1][c] == 0)return 1; // sopra
    if (r < N - 1 && M[r + 1][c] == 0)return 1; // sotto
    if (c > 0 && M[r][c - 1] == 0)return 1; // sinistra
    if (c < N - 1 && M[r][c + 1] == 0)return 1; // destra
    return 0; // altrimenti è sicura
}








void CalcolaPercorsoMin(int M[N][N]) {
    int visitato[N][N] = {0};
    int percorso[N * N] = {0};
    int min = 999;

    index = 0; // reset globale

    TrovaPercorso(M, visitato, percorso, 0, 0, 0);

    if (index == 0) {
        printf("Nessun percorso trovato.\n");
        return;
    }

    printf("I percorsi di questo labirinto sono: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", percorso[i]);
        if (percorso[i] < min)
            min = percorso[i];
    }
    printf("\nIl percorso minimo e': %d\n", min);
}
