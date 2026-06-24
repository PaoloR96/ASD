#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*Var Globali*/
int DP[DIM_N][DIM_M];
void InitDP(int DP[DIM_N][DIM_M],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)DP[i][j]=0;
    }
}

//Con questo metodo devo costruire la DP con la quale andremo ad Aggiornare le H di ogni riga
int CalcolaDP(int DP[DIM_N][DIM_M],int Matrice[DIM_N][DIM_M],int N, int M){
    int MaxArea=0;
    for (int i = 0; i < N; i++){//per ogni riga i
        for (int j = 0; j < M; j++){//per ogni colonna j
            if (Matrice[i][j]==1){
                DP[i][j]=0; //altezza non varia 
            }else{
                if(i==0){
                    DP[i][j]=1;// caso base prima riga
                }else{
                    DP[i][j]=DP[i-1][j]+1; //altezza allo stato (i,j) dipende dall'altezza alla riga precedente+1
                }
            }
        }
        //per ogni riga i-esima andiamo a definire la nostra H
        int AreaRigaX=CalcolaMassimaArea(DP[i],N);
        if(AreaRigaX>MaxArea)MaxArea=AreaRigaX;
    }
    return MaxArea;
}
int CalcolaMassimaArea(int H[DIM_N],int N){
    int MaxArea=0;
    for (int i = 0; i < N; i++){
        int h_corrente=H[i];
        if(h_corrente==0)continue;
        int larghezza=1;
        int pos=i;
        //1.devo trovare la larghezza del mio rettagolo per poter calcolare l'area
        //A.Estensione a sinistra: Devo partire dalla posizione pos devo spostarmi a sx del mio insieme e fermarmi quando trovo una altezza H(j) più piccola(<=) di h_corrente 
        for(int j=pos-1;j>=0 && h_corrente<=H[j];j--)larghezza++;
        //A.Estensione a destra: Devo partire dalla posizione pos devo spostarmi a dx del mio insieme e fermarmi quando trovo una altezza H(j) più piccola di h_corrente 
        for(int j=pos+1;j<N && h_corrente<=H[j];j++)larghezza++;
        int areaC=larghezza*h_corrente;
        if(areaC>MaxArea)MaxArea=areaC;
    }
    return MaxArea;
    
}

