#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

//Inizializzo la matrice con tutti 0
void inizializza(int matrice[RIGHE][COLONNE]) {
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            matrice[i][j] = 0;
        }
    }
}
//Stampa
void stampaSoluzione(int A[], int *solNr) {
    // Stampa il numero della soluzione allineato a destra
    printf("%2d      ", (*solNr)++);

    for (int j = 1; j <= 8; j++) {
        // Stampa la riga per ogni colonna (1-8)
        printf("%d%s", A[j], (j == 8) ? "" : " ");
    }
    printf("\n");
}

void Solve(int rigaFissa, int colFissa) {
    int A[COLONNE+1]; // Array per memorizzare la riga scelta per ogni colonna 
    int contatoreSoluzioni = 1;

    // Stampa l'intestazione una sola volta prima di cercare le soluzioni 
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");

    // Avvia la ricerca dalla prima colonna
    // Passiamo rigaFissa e colFissa
    PosRegina(A, 1, rigaFissa, colFissa, &contatoreSoluzioni);
    
}

/*
Per sapere se una regina in (R1, C1) ne attacca una in (R2, C2), controlliamo le condizioni su:
1)Stessa Riga: R1 = R2
2)Stessa Diagonale 1 (Discendente): R1 - C1 = R2 - C2
3)Stessa Diagonale 2 (Ascendente): R1 + C1 = R2 + C2

*/
int attacco(int r1, int c1, int r2, int c2) {
    // Controllo stessa riga
    if (r1 == r2) return 1; 
    // Controllo diagonale: la distanza tra le righe è uguale a quella tra le colonne 
    if (abs(r1 - r2) == abs(c1 - c2)) return 1; 
    // Nessun conflitto
    return 0; 
}




void PosRegina(int A[], int colonna, int rigaFissa, int colFissa, int *solNr){
    // 1. CONDIZIONE DI USCITA:Se abbiamo superato l'ottava colonna, la soluzione è completate
    if (colonna > COLONNE) {
        stampaSoluzione(A, solNr);
        return;
    }
    // 2. CASO COLONNA DATA DALL'INPUT 
    if (colonna == colFissa) {
        // Verifichiamo se la riga fissa è compatibile con le regine precedenti
        int possibile = 1;
        for (int i = 1; i < colonna; i++) {
            if (attacco(A[i], i, rigaFissa, colonna)) {
                possibile = 0;
                break;
            }
        }
        // Se è sicura, la piazziamo e passiamo alla colonna successiva
        if (possibile) {
            A[colonna] = rigaFissa;
            PosRegina(A, colonna + 1, rigaFissa, colFissa, solNr);
        }
        return; 
    }
    // 3. RICERCA NORMALE (Backtracking) 
    for (int val = 1; val <= COLONNE; val++) {
        int conflitto = 0;
        // Controlliamo se la riga 'val' è sicura rispetto a tutte le colonne precedenti
        for (int i = 1; i < colonna; i++) {
            if (attacco(A[i], i, val, colonna)) {
                conflitto = 1;
                break;
            }
        }

        if (!conflitto) {
            A[colonna] = val; // Piazziamo la regina
            // Proviamo a riempire la colonna successiva
            PosRegina(A, colonna + 1, rigaFissa, colFissa, solNr);
            
        }
    }

    

  
        
}
