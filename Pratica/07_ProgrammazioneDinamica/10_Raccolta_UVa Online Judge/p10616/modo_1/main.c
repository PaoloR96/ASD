#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

// Definizione della variabile globale dichiarata in funzioni.h
long long DP[MAX_N][MAX_M][MAX_D];

int main() {
    CasoTest T[MAX_T];
    int index = 0, valN = 0, valQ = 0;
    printf("SAMPLE INPUT : \n");
    // FASE 1: LETTURA DELL'INPUT
    while (index < MAX_T) {
        // Legge N e Q. Se N=0 e Q=0, il ciclo si interrompe 
        if (scanf("%d %d", &valN, &valQ) != 2) break;
        if (valN == 0 && valQ == 0) break;

        T[index].n = valN;
        T[index].q = valQ;

        // Lettura degli N numeri del set
        for (int i = 0; i < valN; i++) scanf("%d", &T[index].N[i]);
        // Lettura delle Q query (D e M) per questo set
        for (int i = 0; i < valQ; i++)scanf("%d %d", &T[index].Q[i].d, &T[index].Q[i].m);
        index++; // Passa al prossimo slot per il prossimo set
    }
    printf("SAMPLE OUTPUT : \n");
    // FASE 2: ELABORAZIONE E OUTPUT
    for (int i = 0; i < index; i++) {
        // Stampa l'intestazione del SET
        printf("SET %d:\n", i + 1);

        for (int j = 0; j < T[i].q; j++) {
            // Calcoliamo il risultato usando la DP
            long long risultato = CalcolaDP(DP, T[i].N,T[i].n,T[i].Q[j].m,T[i].Q[j].d);
            // Stampa il numero della QUERY e il risultato
            printf("QUERY %d: %lld\n", j + 1, risultato);
        }
    }
    system("PAUSE");
    return 0;
}