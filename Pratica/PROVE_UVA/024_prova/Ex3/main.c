#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
double DP[MAX_STATI];

int main() {
    int N, caso_num = 1;
    double risultato[N_MAX];
    int index=0;
    printf("SAMPLE INPUT: \n");
    // Continua a leggere finché N non è 0
    while (scanf("%d", &N) == 1 && N != 0) {
        int n_totale = 2 * N; // Ci sono 2*N studenti
        Coordinata studenti[2 * N_MAX];

        // Lettura dei dati degli studenti
        for (int i = 0; i < n_totale; i++) scanf("%d %d",&studenti[i].x1, &studenti[i].x2);
        //ELABORAZIONE:

        // 1. Inizializzazione della DP per il caso corrente
        InzitDP(DP);
        // 2. Esecuzione del calcolo DP
        risultato[index] = CalcolaDP(DP, studenti, n_totale);
        index++;

        
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++){
        // 3. Output formattato secondo i requisiti: "Case X: DISTANZA"
        // %.2f arrotonda automaticamente a due decimali
        printf("Case %d: %.2f\n", caso_num++, risultato[i]);
    }
    system("pause");
    return 0;
}

/*
Complessità:O(2^(k) * (k)^2) con k=2N,dove:
                                     2^(k) Rappresenta il numero totale di stati (mask) possibili.
                                     il primo k proviene da trovaStudenti
                                     il secondo K proviene dal secodo for che cerca un partner j tra i restanti studenti liberi
                                
Ricorrenza:


*/