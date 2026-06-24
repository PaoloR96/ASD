#include <stdio.h>
#include "funzioni.h"

void StampaMatrice(int M[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void StampaPercorso(int percorso[N*N][2], int k){
    for(int i = 0; i < k; i++){
        printf("(%d,%d)", percorso[i][0], percorso[i][1]);
        if(i < k-1) printf(" -> ");
    }
    printf("\n");
}

void TrovaPercorso(int M[N][N], int visitato[N][N], int percorso[N*N][2], int riga, int colonna, int pos){

    /* Controlli */
    if (riga < 0 || riga >= N || colonna < 0 || colonna >= N || M[riga][colonna] == 0 || visitato[riga][colonna] == 1)return;

    /* Salvo cella nel percorso */
    percorso[pos][0] = riga;
    percorso[pos][1] = colonna;
    pos++;

    /* Caso base: uscita */
    if (riga == N-1 && colonna == N-1){
        StampaPercorso(percorso, pos);
        return;
    }

    visitato[riga][colonna] = 1;

    /* Quattro direzioni */
    TrovaPercorso(M, visitato, percorso, riga, colonna+1, pos); // destra
    TrovaPercorso(M, visitato, percorso, riga, colonna-1, pos); // sinistra
    TrovaPercorso(M, visitato, percorso, riga+1, colonna, pos); // giù
    TrovaPercorso(M, visitato, percorso, riga-1, colonna, pos); // su

    visitato[riga][colonna] = 0; // backtracking
}

void TrovaNSoluzioni(int M[N][N]){
    int visitato[N][N] = {0};
    int percorso[N*N][2];
    TrovaPercorso(M, visitato, percorso, 0, 0, 0);
}
