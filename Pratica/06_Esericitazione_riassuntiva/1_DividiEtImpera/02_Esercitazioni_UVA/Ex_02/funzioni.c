#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"



void TrovaSeq(int L_num, int L_den, int R_num, int R_den, int a, int b) {
    // Calcolo mediana
    int M_num = L_num + R_num;
    int M_den = L_den + R_den;

    // Se la mediana è la frazione target → fine
    if (a * M_den == b * M_num) {
        return;
    }
    // T è a sinistra della mediana → aggiungi 'L'
    else if (a * M_den < b * M_num) {
        printf("L");
        TrovaSeq(L_num, L_den, M_num, M_den, a, b);
    }
    // T è a destra della mediana → aggiungi 'R'
    else {
        printf("R");
        TrovaSeq(M_num, M_den, R_num, R_den, a, b);
    }
}




void CalcolaSequenze(int mn[SIZE][2], int index){
    for (int i = 0; i < index; i++){
        TrovaSeq(0, 1, 1, 0, mn[i][0], mn[i][1]);
        printf("\n");
    }
}