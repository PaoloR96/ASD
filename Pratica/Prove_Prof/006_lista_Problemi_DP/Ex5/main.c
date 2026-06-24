#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int risultato[MAX];
    int N, dimp, Pivot[MAX];
    int index = 0;
    
    //1.Fase d'inserimento
    while (1){
        //Inserisco N e i pivot
        if (scanf("%d", &N) != 1 || N == 0) break;
        scanf("%d", &dimp);
        
        //2.Costruiamo il vettore dei pivot includendo gli estremi
        Pivot[0] = 0;
        //pivot dall'input vanno memorizzati da 1 a dimp
        for (int i = 1; i <= dimp; i++) {
            scanf("%d", &Pivot[i]);
        }
        Pivot[dimp + 1] = N;
        int p_tot = dimp + 2;
        
        //3.Applico la programmazione dinamica
        //Inizializzo la DP (Passando p_tot come richiesto dalla nuova logica di CalcolaDP)
        InitDP(DP, p_tot);
        
        //Calcolo la soluzione ottima
        risultato[index] = CalcolaDP(DP, p_tot, Pivot);
        
        //4.Passo al caso di test successivo
        index++;
    }
    
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++) printf("%d \n", risultato[i]);
    
    system("pause");
    return 0;
}

/*
Complessità:O(N^3)
Ricorrenza:Definiti gli intervalli base (segmenti tra due pivot adiacenti), la transizione 
           per un macro-intervallo che va dall'intervallo i all'intervallo j è:

            Caso Base (lunghezza len = 1):
                DP[i][i] = 0   per ogni 0 <= i < N_intervalli

            Passo Ricorsivo (lunghezza len > 1):
                DP[i][j] = min { DP[i][k] + DP[k+1][j] } + costo_attuale per i <= k < j
                                                           dove costo_attuale = Pivot[j+1] - Pivot[i]

*/