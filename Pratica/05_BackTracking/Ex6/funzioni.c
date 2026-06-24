#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

// Inizializza la matrice ponendo tutti gli elementi a 0
void InitMatrice(int M[N][N]){
    for (int  i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            M[i][j]=0; // Nessuna regina presente
        }
    }
}

// Stampa la matrice a video
void StampaMatrice(int M[N][N]){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]); // 1 indica regina, 0 casella vuota
        }
        printf("\n");
    }
}

// Controlla se è possibile posizionare una regina nella cella (riga, colonna)
int posizioneValida(int M[N][N], int riga, int colonna){

    // Controllo colonna: non deve esserci un'altra regina nella stessa colonna
    for(int i = 0; i < riga; i++){
        if (M[i][colonna] == 1) 
            return 0; // conflitto → posizione non valida
    }

    // Controllo diagonale superiore sinistra
    int i = riga - 1;
    int j = colonna - 1;
    while (i >= 0 && j >= 0){
        if (M[i][j] == 1) 
            return 0; // conflitto su diagonale
        i--;
        j--;
    }

    // Controllo diagonale superiore destra
    i = riga - 1;
    j = colonna + 1;
    while (i >= 0 && j < N){
        if (M[i][j] == 1) 
            return 0; // conflitto su diagonale
        i--;
        j++;
    }

    return 1; // posizione sicura → si può mettere la regina
}

// Funzione ricorsiva che prova a posizionare una regina riga per riga
int posizionaRegina(int M[N][N], int riga){

    // Caso base: se abbiamo piazzato regine in tutte le righe, la soluzione è trovata
    if (riga == N){
        return 1;
    }

    // Prova tutte le colonne della riga corrente
    for (int col = 0; col < N; col++){

        // Se la posizione è valida, piazza la regina
        if (posizioneValida(M, riga, col) == 1){
            M[riga][col] = 1; // posiziona regina

            // Chiamata ricorsiva sulla riga successiva
            if (posizionaRegina(M, riga + 1) == 1)
                return 1; // soluzione trovata

            // Se non funziona, rimuovi la regina (backtracking)
            M[riga][col] = 0;
        }
    }

    // Se nessuna colonna è valida, torna indietro
    return 0;
}

// Avvia il processo e stampa la soluzione
void risolviNRegine(int M[N][N]){
    if(posizionaRegina(M,0)==1){
        StampaMatrice(M);
    }else{
        printf("Nessuna soluzione\n");
    }
}