#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

void StampaInput(Cubo A[], int numCubi) {
    for(int i = 0; i < numCubi; i++) { 
        for(int j = 0; j < C; j++) {
            printf("%d ", A[i].color[j]);
        }
        printf("\n");
    }
}

void InitDP(int dp[N][C],Parent parent[N][C],int numCubi) {
    for(int i = 0; i < numCubi; i++) {
        for(int j = 0; j < C; j++) {
            dp[i][j] = 1;
            parent[i][j].cubo = -1; // -1 indica che non c'è un cubo sopra (inizio catena)
            parent[i][j].faccia = -1;
        }
    }
}

int CalcolaDP(int dp[N][C],Parent parent[N][C],Cubo A[],int numCubi,int *bestI, int *bestF){
        /* Mappatura facce opposte: front(0)-back(1), left(2)-right(3), top(4)-bottom(5) */
        int Opposta[C]={1,0,3,2,5,4};
        /*Ricorrenza*/
        for (int i = 0; i < numCubi; i++){
            for (int f = 0; f < C; f++){
                int coloreTopI=A[i].color[f];// Scegliamo la faccia Top del cubo attuale
                // Ora cerchiamo tra i cubi precedenti (SOPRA)
                for (int j = 0; j < i; j++) {
                    for (int f_prev = 0; f_prev < 6; f_prev++){ // Faccia Top del cubo sopra
                        // Troviamo il colore del fondo del cubo sopra
                        int facciaBottomJ = Opposta[f_prev];
                        int coloreBottomJ = A[j].color[facciaBottomJ];
                        // CONDIZIONE DI INCASTRO
                        if (coloreBottomJ == coloreTopI) {
                            // Se la torre che finisce con j è utile per allungare i
                            if (dp[j][f_prev] + 1 > dp[i][f]) {
                                dp[i][f] = dp[j][f_prev] + 1;
                                parent[i][f].cubo = j;      // Memorizziamo il legame
                                parent[i][f].faccia = f_prev;
                            }
                        }
                    }
                }
            }
        }
        
        int maxH = 0;
        int startCubo = -1, startFaccia = -1;
        for (int i = 0; i < numCubi; i++) {
            for (int f = 0; f < 6; f++) {
                if (dp[i][f] > maxH) {
                    maxH = dp[i][f];
                   *bestI = i; // Salvi l'indice del cubo
                   *bestF = f; // Salvi l'indice della faccia
                }
            }
        }
        return maxH;
}


void stampaTorre(Parent parent[N][C], int i, int f) {
    // Caso base: se l'indice del cubo è -1, abbiamo finito la risalita
    if (i == -1) return;

    // 1. Chiamata ricorsiva: passiamo i VALORI del padre
    // parent[i][f].cubo e parent[i][f].faccia sono gli indici salvati nella DP
    stampaTorre(parent, parent[i][f].cubo, parent[i][f].faccia);

    // 2. Stampa (avviene durante la risalita dello stack, dall'alto al basso)
    char *nomiFacce[] = {"front", "back", "left", "right", "top", "bottom"};
    
    // Usiamo i + 1 perché l'output vuole il seriale del cubo (1, 2, 3...)
    printf("%d %s\n", i + 1, nomiFacce[f]);
}