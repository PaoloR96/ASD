#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

void InitDp(int dp[N][M],int parent[N][M],int righe,int colonne){
    for(int i = 0; i < righe; i++) {
        for(int j = 0; j < colonne; j++) {
            dp[i][j]=INT_MAX;
            parent[i][j]=INT_MAX;
        }
    }

}

int Minimo(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}
int confronta(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
void CalcolaDP(int dp[N][M],int parent[N][M],int matrice[][6],int righe,int colonne){
    /*Definizione Caso Base*/
    for ( int i = 0; i < righe; i++)dp[i][colonne-1]=matrice[i][colonne-1];
    /*Ricorrenza dinamica*/

    for ( int x = colonne-2; x >=0; x--){
        for (int i = 0; i < righe; i++){
            // Calcoliamo i tre indici adiacenti con la logica cilindrica
            int rSopra = (i - 1 + righe) % righe;
            int rCentro = i;
            int rSotto = (i + 1) % righe;
            //ordinamento degli indici
            int r[3] = {rSopra, rCentro, rSotto};
            qsort(r, 3, sizeof(int), confronta);
            //Trovo il minimo tra i 3 elementi selezionati
            int vMin = Minimo(dp[r[0]][x + 1],dp[r[1]][x + 1], dp[r[2]][x + 1]);
            //Aggiorno la matrice
            dp[i][x] = matrice[i][x] + vMin;
            // Gestione della priorità lessicografica in caso di parità 
            if (vMin == dp[r[0]][x + 1]) parent[i][x] = r[0];
           
            else if (vMin == dp[r[1]][x + 1])parent[i][x] = r[1];
            
            else parent[i][x] = r[2];
        }
         
    }
    
}
