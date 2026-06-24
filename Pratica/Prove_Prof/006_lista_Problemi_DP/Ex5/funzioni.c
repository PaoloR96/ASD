#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header

int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int N){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            DP[i][j]=0;
        }
    }
    
}

int CalcolaDP(int DP[MAX][MAX], int N, int Pivot[MAX]) {
    // Calcoliamo quanti intervalli base ci sono tra i pivot (p_tot - 1):
    // Senza questa considerazione, se avessi 4 punti (p_tot = 4) l'algoritmo calcolerebbe 4 intervalli, 
    // di cui uno "fantasma" che andrebbe fuori dai limiti dell'array.
    // Riducendo a N_intervalli, se ho 4 punti avrò esattamente i 3 intervalli reali: (0,1), (1,2), (2,3).
    int N_intervalli = N - 1;


    //Ricorsione:
    for (int len = 2; len <= N_intervalli; len++) { //Definisco la lunghezza del mio intervallo len (in numero di segmenti)
        
        //1:devo definire l'ampiezza del mio intervallo di osservazione(i,j)
        for (int i = 0; i <= N_intervalli - len; i++) { //punto inizio d'osservazione
            int j = i + len - 1; //definisco la fine del punto d'osservazione
            
            //2:In funzione (i,j)devo calcolare il costo associato
            // Il costo attuale è la lunghezza reale del macro-segmento, dal punto Pivot[i] al punto Pivot[j+1]
            int costo_attuale = Pivot[j + 1] - Pivot[i]; // Lunghezza del sotto-array corrente
            
            //Inizializzo a "infinito" per poter trovare il min
            DP[i][j] = INT_MAX;
            
            //3.Analizzo i costi all'interno del mio intervallo
            // Cerco un punto di rottura 'k' che separi i segmenti da i a k e da k+1 a j, esattamente come nella tua guida
            for (int k = i; k < j; k++) {
                int valoreTmp = DP[i][k] + DP[k + 1][j] + costo_attuale;
                DP[i][j] = min2(DP[i][j], valoreTmp);
            }
        }
    }
    
    //4.Ritorna il valore calcolato
    // Il costo minimo per l'intera sequenza si troverà nella cella che va dal primo all'ultimo intervallo
    return DP[0][N_intervalli - 1];
}
int min2(int a,int b){return(a<b)?a:b;}