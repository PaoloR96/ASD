#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void RiempiCasoTest(char Scacchiera[RC][RC],int n){
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                scanf(" %c",&Scacchiera[r][c]);
            }
        }
}


/*VARIABILE GLOBALE*/
int Contatore=0;

void PosizionaRegina(char Scacchiera[RC][RC],int n,int riga){
    // 1. CONDIZIONE DI USCITA: Se riga == n, abbiamo piazzato n regine con successo
    if(riga==n){
            Contatore++;
            return;
    }
    //Ricorrenza
    for (int colonna = 0; colonna < n; colonna++){
        if(Scacchiera[riga][colonna]=='.'){//posizione libera
            if(CheckVerticale(Scacchiera,riga,colonna,n) && (CheckDiagonaleSX(Scacchiera,riga,colonna, n))&&(CheckDiagonaleDX(Scacchiera,riga,colonna, n))){
                    //posso piazzare la regina
                    Scacchiera[riga][colonna]='Q';
                    PosizionaRegina(Scacchiera,n,riga+1);//passo alla riga successiva
                    // BACKTRACKING: Fondamentale per esplorare le altre possibilità
                    Scacchiera[riga][colonna]='.';
            }
            
        }
    }
}


// Controlla la diagonale Nord-Ovest
int CheckDiagonaleSX(char Scacchiera[RC][RC], int riga, int col, int n) {
    int i = riga, j = col;
    while (i >= 0 && j >= 0) {
        if (Scacchiera[i][j] == 'Q') return 0; // Attacco!
        i--; j--;
    }
    return 1;
}

// Controlla la diagonale Nord-Est
int CheckDiagonaleDX(char Scacchiera[RC][RC], int riga, int col, int n) {
    int i = riga, j = col;
    while (i >= 0 && j < n) {
        if (Scacchiera[i][j] == 'Q') return 0; // Attacco!
        i--; j++;
    }
    return 1;
}


// Controlla se c'è una regina sopra nella stessa colonna
int CheckVerticale(char Scacchiera[RC][RC], int riga, int col, int n) {
    for (int i = 0; i < riga; i++) {
        if (Scacchiera[i][col] == 'Q') return 0; // Attacco!
    }
    return 1;
}