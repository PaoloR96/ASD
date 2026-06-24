#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int RiempiCasoTest(int Monete[DIM]) {
    int cont = 0;
    for (int i = 0; i < 6; i++) {
        if (scanf("%d", &Monete[i]) != 1) return 1;
        if (Monete[i] == 0) cont++;
    }
    if (cont == 6) return 1;
    return 0;
}

void InitDp(int DP[DIM_MAX]) {
    for (int i = 0; i < DIM_MAX; i++) DP[i] = INT_MAX;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}
//gestiamo le monete del mio portafoglio che sono limitate
void CalcolaDpUtente(int Monete[DIM], int tagli[], int DP[DIM_MAX]) {
    DP[0] = 0;
    for (int i = 0; i < DIM; i++) { //per ogni monetaAtt vado a definire come rappresentarle
        int monetaAtt = tagli[i];
        int nMonete = Monete[i];
        for (int j = 0; j < nMonete; j++) {
            for (int k = DIM_MAX - 1; k >= monetaAtt; k--) { //le monete solo limitate
                if (DP[k - monetaAtt] != INT_MAX) {
                    DP[k] = min(DP[k], DP[k - monetaAtt] + 1);
                }
            }
        }
    }
}
////gestiamo le monete del negoziante che sono illimitate
void CalcolaDpNegoziante(int tagli[], int DP[DIM_MAX]) {
    //caso base
    DP[0] = 0;
    //ricorrenza
    for (int i = 0; i < DIM; i++) {
        int monetaAtt = tagli[i];
        for (int k = monetaAtt; k < DIM_MAX; k++) {//le monete sono illimitate
            if (DP[k - monetaAtt] != INT_MAX) {
                DP[k] = min(DP[k], DP[k - monetaAtt] + 1);
            }
        }
    }
}

void minTotale(int DpNegoziante[DIM_MAX], int DpUtente[DIM_MAX], int target) {
    int minimoTotale = INT_MAX;
    for (int i = target; i < DIM_MAX; i++) {
        if (DpUtente[i] != INT_MAX && DpNegoziante[i - target] != INT_MAX) {
            minimoTotale = min(minimoTotale, DpUtente[i] + DpNegoziante[i - target]);
        }
    }
    printf("%3d\n", minimoTotale);
}