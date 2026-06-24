#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funzioni.h"  // Include il file header
Coordinate TrovaPosizioneLibera(int M[MAX][MAX]) {
    Coordinate pos = {0, 0};
    for (int r = 0; r < MAX; r++) {
        for (int col = 0; col < MAX; col++) {
            if (M[r][col] == 2) {
                pos.x = r;
                pos.y = col;
                return pos;
            }
        }
    }
    return pos;
}
/*-----VARIABILI GLOBALI-----*/
const int ScacchieraTarget[MAX][MAX] = {
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 0, 2, 1, 1}, // 2 rappresenta lo spazio vuoto
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};
int minMosseGlobal = 11;
/*--------------------------*/
void CalcolaNumeroMinSequenze(int M[MAX][MAX], int rigaAtt, int colonnaAtt, int mosseFatte) {
    // Passo 1: Calcolo delle differenze (Euristica h)
    // Contiamo quanti cavalieri sono fuori posto rispetto alla ScacchieraTarget.
    int fuoriPosto = contaDifferenze(M);

    // Passo 1.A: Condizione di potatura (Pruning)
    // Se le mosse fatte + il minimo di mosse necessarie (fuoriPosto) superano il limite, interrompiamo
    // Il problema richiede una soluzione entro 10 mosse; se arriviamo a 11 o superiamo il minimo globale, usciamo
    if (mosseFatte + fuoriPosto >= minMosseGlobal || mosseFatte >= 11) return;

    // Passo 2: Condizione di vittoria
    // Se non ci sono più differenze (fuoriPosto == 0), abbiamo raggiunto la configurazione target
    if (fuoriPosto == 0) {
        if (mosseFatte < minMosseGlobal) minMosseGlobal = mosseFatte;
        return;
    }

    // Passo 3: Ricorrenza, prova le 8 mosse a "L"
    int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; i++) {
        // Calcolo delle nuove coordinate per lo spostamento
        int nuovaR = rigaAtt + dr[i];
        int nuovaC = colonnaAtt + dc[i];

        // Verifichiamo se la mossa è all'interno dei confini della scacchiera 5x5
        if (PosizioneValida(nuovaR, nuovaC)) {
            // Eseguiamo lo swap per muovere il cavaliere nella posizione vuota
            Swap(&M[rigaAtt][colonnaAtt], &M[nuovaR][nuovaC]);

            // Passo 3.A: Chiamata ricorsiva per la mossa successiva
            CalcolaNumeroMinSequenze(M, nuovaR, nuovaC, mosseFatte + 1);

            // Passo 3.B: BACKTRACKING
            // Ripristiniamo la posizione originale per esplorare altre strade
            Swap(&M[rigaAtt][colonnaAtt], &M[nuovaR][nuovaC]);
        }
    }
}

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool PosizioneValida(int r, int c) {
    return (r >= 0 && r < 5 && c >= 0 && c < 5);
}


int contaDifferenze(int M[MAX][MAX]) {
    int n = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            // Conta solo se c'è un cavaliere (0 o 1) ed è nel posto sbagliato
            if (M[i][j] != 2 && M[i][j] != ScacchieraTarget[i][j]) {
                n++;
            }
        }
    }
    return n; 
}

void RiempiMatrice(int M[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%d", &M[i][j]);
        }
    }
}