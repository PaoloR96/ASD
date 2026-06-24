#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "funzioni.h"

int main() {
    // 1. Definiamo il grafo
    // Nodi coinvolti: A, B, C, D, E, F, G, H (8 nodi)
    Grafo G = {
        .Nodo = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
        .numNodi = 8,
        .Matrice = {0} // Inizializziamo a zero
    };

    // 2. Creo la lista di adiacenza
    // A:FB (A connesso a F e B)
    G.Matrice[0][5] = G.Matrice[5][0] = 1; // A-F
    G.Matrice[0][1] = G.Matrice[1][0] = 1; // A-B

    // B:GC (B connesso a G e C)
    G.Matrice[1][6] = G.Matrice[6][1] = 1; // B-G
    G.Matrice[1][2] = G.Matrice[2][1] = 1; // B-C

    // D:GC (D connesso a G e C)
    G.Matrice[3][6] = G.Matrice[6][3] = 1; // D-G
    G.Matrice[3][2] = G.Matrice[2][3] = 1; // D-C

    // F:AGH (F connesso a A, G e H)
    G.Matrice[5][0] = G.Matrice[0][5] = 1; // F-A
    G.Matrice[5][6] = G.Matrice[6][5] = 1; // F-G
    G.Matrice[5][7] = G.Matrice[7][5] = 1; // F-H

    // E:HD (E connesso a H e D)
    G.Matrice[4][7] = G.Matrice[7][4] = 1; // E-H
    G.Matrice[4][3] = G.Matrice[3][4] = 1; // E-D

    // 3. Reset delle variabili globali prima del calcolo
    minimoGlob = INT_MAX;
    memset(usato, 0, sizeof(usato));
    memset(soluzioneOttima, 0, sizeof(soluzioneOttima));

    // 4. Avviamo il calcolo della sequenza ottima
    char attuale[MAX_NODI];
    CalcolaSequenza(attuale, 0, G, 0);

    // 5. Output finale
    for (int i = 0; i < G.numNodi; i++) printf("%c ", soluzioneOttima[i]);
    printf("-> %d\n", minimoGlob);
    system("pause");
    return 0;
}


/*Complessità:O(N!)*/