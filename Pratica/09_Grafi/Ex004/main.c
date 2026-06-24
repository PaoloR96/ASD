#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Dichiariamo la matrice vis come globale per evitare di sovraccaricare lo stack
// e permettere sia al main che alla BFS di accedervi facilmente.
int visitato[MAX_GRID][MAX_GRID];

int main() {
    int R, C; // Righe e Colonne totali della griglia
    int rowsWithBombs; // Numero di righe che contengono bombe
    int r, numBombs, c; // Variabili di appoggio per la lettura delle bombe
    int sR, sC, tR, tC; // Coordinate di partenza (Start) e arrivo (Target)

    /* Ciclo infinito di lettura: termina quando R e C sono entrambi 0 */
    while (scanf("%d %d", &R, &C) == 2 && (R != 0 || C != 0)) {
        
        // 1. Reset della matrice visitato per il nuovo caso di test
        // Impostiamo tutto a 0 (percorso libero)
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                visitato[i][j] = 0;
            }
        }

        // 2. Lettura del numero di righe che contengono mine
        scanf("%d", &rowsWithBombs);
        for (int i = 0; i < rowsWithBombs; i++) {
            // Per ogni riga, leggiamo l'indice della riga e quante bombe contiene
            scanf("%d %d", &r, &numBombs);
            for (int j = 0; j < numBombs; j++) {
                // Leggiamo la colonna di ogni singola bomba
                scanf("%d", &c);
                // Segniamo la cella come 1 (occupata/visitata)
                // Così la BFS la considererà un ostacolo insuperabile
                visitato[r][c] = 1;
            }
        }

        // 3. Lettura delle coordinate di partenza (sR, sC) e arrivo (tR, tC)
        scanf("%d %d %d %d", &sR, &sC, &tR, &tC);

        // 4. Esecuzione del BFS
        // Passiamo la matrice visitato che contiene già tutte le bombe piazzate
        int risultato = bfs_bombs(sR, sC, tR, tC, R, C, visitato);

        // 5. Stampa del risultato (numero minimo di passi)
        if (risultato != -1) {
            printf("%d\n", risultato);
        }
    }
    system("pause");
    return 0;
}
/*Complessità:O(V+E)*/