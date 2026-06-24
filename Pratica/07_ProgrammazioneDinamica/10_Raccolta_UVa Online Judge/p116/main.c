#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int matrice[][6] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}
    };
    int righe = sizeof(matrice) / sizeof(matrice[0]);
    int colonne = sizeof(matrice[0]) / sizeof(matrice[0][0]);
    int dp[N][M],parent[N][M];
    //Inizializzo Dp e Parent;
    InitDp(dp,parent,righe,colonne);
    //Calcolo Percorso minimo e costi in DP e Parent
    CalcolaDP(dp, parent, matrice, righe, colonne);
    //Trova la riga di partenza nella colonna 0 con il costo minimo
    // Se i costi sono uguali, scegliamo la riga più piccola per la lessicografia
    int rigaInizio = 0;
    for (int i = 1; i < righe; i++) {
        if (dp[i][0] < dp[rigaInizio][0]) {
            rigaInizio = i;
        }
    }
    // 3. Stampa il percorso (sequenza di n interi separati da spazi) 
    int r = rigaInizio;
    for (int j = 0; j < colonne; j++) {
        // Stampiamo r+1 perché il problema usa indici riga da 1 a m 
        printf("%d%s", r + 1, (j == colonne - 1) ? "" : " ");
        
        // Ci spostiamo alla riga successiva salvata in parent
        if (j < colonne - 1) {
            r = parent[r][j];
        }
    }
    printf("\n");
    printf("%d\n", dp[rigaInizio][0]);
    system("PAUSE");
    return 0;
}
/*
Complessità:O(m*n) con m numero di righe e n numero di colonne
Ricorrenza: dp[i][x] = matrice[i][x] + min(dp[r[0]][x + 1], dp[r[1]][x + 1], dp[r[2]][x + 1])


*/