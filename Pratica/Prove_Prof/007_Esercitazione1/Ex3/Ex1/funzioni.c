#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int lunghezza){
    for (int i = 0; i < lunghezza; i++){
        for (int j = 0; j < lunghezza; j++)DP[i][j]=0;
    }
}
int CalcolaDP(int DP[MAX][MAX],int lunghezza,int PuntiTaglio[MAX]){
    //Devo definire l'intervallo di tagli che vado ad effuare 
    //in questo modo se ho una lunghezza=4, supponenendo di avere(0,1,2,3)punti
    //con quesa osservazione considererò come intervalli:(0,1),(1,2),(2,3)
    //Senza questa osservazione avrei un bordo fantasma e quindi potrei andare in overflow
    int numeroTagli=lunghezza-1;
    for (int len = 2; len <= numeroTagli; len++){
        for (int i = 0; i <= numeroTagli-len; i++){//Definisco il mio punto di inizio osservazione i
            int j=i+len-1;//Definisco il mio punto di fine osservazione i
            // Inizializziamo a un valore infinito per poter calcolare il minimo
            DP[i][j] = INT_MAX;
            
            int CostoAtt=PuntiTaglio[j+1]-PuntiTaglio[i]; //considero la macro-sequnenza di taglio (j+1,i)
            //Vado ada analizzare il mio intervallo per ogni k £(i,j)
            for (int k = i; k < j; k++){
                int valoreAtt=DP[i][k]+DP[k+1][j]+CostoAtt;
                //Prendo il minimo tra DP[i][j] ed il nuovo valore calcolato 
                DP[i][j]=min2(DP[i][j],valoreAtt);
            }
        }
    }
    return DP[0][numeroTagli-1];
}
int min2(int a,int b){return(a<b)?a:b;}
