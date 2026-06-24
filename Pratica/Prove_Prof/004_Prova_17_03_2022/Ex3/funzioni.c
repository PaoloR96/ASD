#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALE*/
int DP[MAX][MAX];
void InitDP(int DP[MAX][MAX],int dim){
    //Ogni singola lettera è un palindromo di lunghezza 1.
    for (int i = 0; i < dim; i++) DP[i][i]=1;
    
}
int CalcolaDP(int DP[MAX][MAX],char Stringa[MAX_STINGA],int dim){
        for (int i = dim-1; i >= 0; i--){//Parto da destra:Con i andiamo a definire l'inizio dell'intervallo d'osservazione 
            char carattereX=Stringa[i];
            for (int j = i+1; j < dim; j++){//j andimo a definire la fine dell'intervallo di osservazione
                //Valutiamo i carattere appartenenti all'intervallo(i,j)
                if (carattereX==Stringa[j]){//Se sono uguali
                    DP[i][j]=DP[i+1][j-1]+2; ////formano un palindromo di lunghezza 2
                }else{
                    //Prendo il massimo tra i due caratteri
                    DP[i][j]=max2(DP[i+1][j],DP[i][j-1]);
                }   
            }
        }
    return DP[0][dim-1];
}

int max2(int a,int b){return (a>b)?a:b;}


/*
Questo tipo di approccio prende il LPS(LONGEST PALINDROM SEQUENCE)dove lavoro su una sola stringa 
gestendo le righe in modo adiacenti;
In alternativa potevo usare il classico LCS dove la stringa S la ribaltavo e applicavo il classico LIS

Dal punto di vista della complessità non cambia NULLA!
*/