#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/*Inizializzazione DP*/
void InitDP(int DP[DIM_N][DIM_M],int N,int M){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)DP[i][j]=0;
    }
}
int max2(int a,int b){return(a>b)?a:b;}
/*Costruisce la matrice DP (istogramma) riga per riga*/
int CalcolaDP(int DP[DIM_N][DIM_M],int Matrice[DIM_N][DIM_M],int N, int M){
     int MaxArea=0;
    // 1. Costruisco la matrice DP: ogni riga rappresenterà le altezze (H) dell'istogramma
    for (int i = 0; i < N; i++){//Per ogni riga i-esima
        for (int j = 0; j < M; j++){//Per ogni colonna j-esima
            if (Matrice[i][j]==1){
                DP[i][j]=0;// H si azzera se trova un ostacolo
            }else{
                if (i==0){
                    DP[i][j]=1;//Caso base prima riga: altezza iniziale
                }else{
                    DP[i][j]=DP[i-1][j]+1; // Passo induttivo: si somma alla cella superiore
                }     
            }
        }
        //2. Per ogni riga calcoliamo l'area massima dell'istogramma appena costruito
        int AreaRigaX=CalcolaMassimaArea(DP[i],M);
        MaxArea=max2(MaxArea,AreaRigaX);
    }
    //3.Ritorna la soluzione globale ottima
    return MaxArea;
}

/* Calcola l'area del rettangolo massimo in un istogramma */
int CalcolaMassimaArea(int H[DIM_M],int M){
    int MaxArea=0;
    for (int i = 0; i < M; i++){// Per ogni barra i dell'istogramma
        int h_corrente=H[i];
        if(h_corrente==0)continue;
        int larghezza=1;
        int pos=i;
        // 1. Calcolo la larghezza del rettangolo massimo avente altezza 'h_corrente'
        
        // A. Estensione a sinistra: mi sposto verso sx finché l'altezza adiacente 
        //è maggiore o uguale a h_corrente (fermandomi se è strettamente minore)
        for(int j=pos-1;j>=0 && h_corrente<=H[j];j--)larghezza++;
        // B. Estensione a destra: mi sposto verso dx finché l'altezza adiacente 
        // è maggiore o uguale a h_corrente (fermandomi se è strettamente minore)
        for(int j=pos+1;j<M && h_corrente<=H[j];j++)larghezza++;
        
        // 2. Calcolo l'area per l'altezza corrente e aggiorno il massimo se necessario
        int areaC=larghezza*h_corrente;
        if(areaC>MaxArea)MaxArea=areaC;
    }
    return MaxArea;
}