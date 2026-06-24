#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALE*/
int DP[MAX_S][MAX_S];

void RiempiCasoTest(CasoTest *T) {
    if (scanf("%d %d", &T->m, &T->S) != 2) return; 
    
    for (int i = 0; i < T->m; i++) scanf("%d %d", &T->E[i].e1, &T->E[i].e2);
    
}

void InizializzaDP(int DP[MAX_S][MAX_S],int S){
    for (int i = 0; i <= S; i++){
        for (int j = 0; j <= S; j++)DP[i][j]=INT_MAX;
    }
    
}

void CalcolaDP(int DP[MAX_S][MAX_S],CasoTest T){
    //1.Caso base
    DP[0][0]=0;
    //2.Ricorrenza
    for (int m = 0; m <T.m ; m++){//per ogni coppia di moneta(vx,vy)
        int vx=T.E[m].e1;
        int vy=T.E[m].e2;
        for (int i = vx; i <=T.S; i++){
            for (int k = vy; k <=T.S; k++){
                //Condizione per evitare un overflow
               if(DP[i - vx][k - vy] != INT_MAX) DP[i][k]=min2(DP[i][k],DP[i-vx][k-vy]+1); 
            }    
        }
    }
}






int min2(int a ,int b){
    return (a<b)?a:b;
}

Risultato TrovaSoluzioneOttima(int DP[MAX_S][MAX_S],CasoTest T){
    Risultato r={0,false};
    int risultato_minimo=INT_MAX;
    int S_quadrato = T.S * T.S; // S^2
    for (int i = 0; i < T.S; i++){
        for (int j = 0; j < T.S; j++){
            if(S_quadrato ==(i*i)+(j*j))risultato_minimo=min2(DP[i][j],risultato_minimo);
        }
    }
    if(risultato_minimo==INT_MAX){
        r.valore=INT_MAX;
        r.stato=0;
    }else{
        r.valore=risultato_minimo;
        r.stato=1;
    }
    return r;
}