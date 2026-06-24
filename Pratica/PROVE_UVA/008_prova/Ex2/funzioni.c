#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*Definizione REALE Variabili globali*/
int soluzioniTrovate = 0;
int codiceVincente[DIM];
void CalcolaSequenza(CasoTest S[], int G, int guess[DIM], int pos){
    // Caso base: abbiamo costruito un numero completo (pos arriva a 4)
    if (pos == DIM) {
        int casiTestSuperati = 0;
        //vediamo quanti casi di test supera questo numero
        for (int i = 0; i < G; i++) {
            if (confrontoX(S[i].Segreto, guess) == S[i].x && confrontoY(S[i].Segreto, guess) == S[i].y) {
                casiTestSuperati++;
            } else {
                break; // Se fallisce un solo test, questo guess non è valido
            }
        }
        // Se il guess rispetta tutti i G indizi, lo salviamo
        if (casiTestSuperati == G) {
            soluzioniTrovate++;
            for (int k = 0; k < DIM; k++) codiceVincente[k] = guess[k];
        }
        return;
    }
    // Ottimizzazione: se abbiamo già trovato più di una soluzione, 
    // l'output sarà comunque 'indeterminate'
    if (soluzioniTrovate > 1) return;
    //genero una nuova sequenza (0000-9999) e la testo 
    // Ciclo di backtracking: prova le cifre da 0 a 9 per la posizione attuale
    for (int cifra = 0; cifra <= 9; cifra++) {
        guess[pos] = cifra;
        CalcolaSequenza(S, G, guess, pos + 1);
    }
}

int confrontoX(int segreto[DIM], int guess[DIM]) {
    int x = 0;
    for (int i = 0; i < DIM; i++) {
        if (segreto[i] == guess[i]) x++;
    }
    return x;
}

int confrontoY(int segreto[DIM], int guess[DIM]) {
    int y = 0;

    int usatoSegreto[DIM] = {0};
    int usatoGuess[DIM] = {0};

    // Prima escludiamo quelli già corretti (come X)
    for (int i = 0; i < DIM; i++) {
        if (segreto[i] == guess[i]) {
            usatoSegreto[i] = 1;
            usatoGuess[i] = 1;
        }
    }

    // Calcolo Y
    for (int i = 0; i < DIM; i++) {
        if (usatoGuess[i]) continue;

        for (int j = 0; j < DIM; j++) {
            if (usatoSegreto[j]) continue;

            if (guess[i] == segreto[j]) {
                y++;
                usatoSegreto[j] = 1;
                break;
            }
        }
    }

    return y;
}