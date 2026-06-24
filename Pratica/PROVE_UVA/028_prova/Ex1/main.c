#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int N, Q;
    int S[MAX_CHIMPS];
    printf("SAMPLE INPUT:\n");
    // Lettura del numero di lady chimps 
    if (scanf("%d", &N) != 1) return 0;

    // Lettura delle altezze 
    for (int i = 0; i < N; i++) scanf("%d", &S[i]);
    // Lettura del numero di query 
    if (scanf("%d", &Q) != 1) return 0;
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < Q; i++) {
        int H;
        scanf("Inserire H:%d", &H); // Altezza di Luchu per questa query
        // Esecuzione delle ricerche binarie
        int ts = TallestShorter(S, N, H);
        int st = ShortestTaller(S, N, H);
        // Stampa con gestione della 'X' per i casi impossibili
        if (ts == -1) printf("X ");
        else printf("%d ", ts);
        if (st == -1) printf("X\n");
        else printf("%d\n", st);
    }
    system("pause");
    return 0;
}

/*Complessità:O(Q*logN)   dove Q rappresenta le H di Luchu
                          dove N rappresenta il numero di campioni
*/

