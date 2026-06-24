#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

/*VAR GLOBALE*/
int DP[MAX][MAX];

/*Fase di inizializzazione: i singoli caratteri (matrice sulla diagonale) 
  hanno lunghezza palindroma pari a 1. Il resto a 0*/
void InitDP(int DP[MAX][MAX],int dim){
    for (int i = 0; i < dim; i++)DP[i][i]=1;
    
}
int CalcolaDP(int DP[MAX][MAX],char Stringa[MAX_STRINGA],int dim){
    // Parto dall'ultimo carattere e vado a ritroso per costruire la soluzione bottom-up
    for (int i = dim-1; i >= 0; i--){//Parto dal "penultimo" carattere 
        char CarattereX=Stringa[i];
        for (int j = i+1; j<dim ; j++){//Parto dal carattere adiacente j
            //in questo modo definisco l'intervallo di osservazione(i,j)
            if (CarattereX==Stringa[j]){
                DP[i][j]=DP[i+1][j-1]+2; // Se i caratteri estremi corrispondono, si aggiunge 2 alla sottostringa interna
            }else{
                DP[i][j]=max2(DP[i+1][j],DP[i][j-1]);// Altrimenti, prendo il massimo escludendo l'inizio o la fine
            }
        }
    }
    return DP[0][dim-1];
}

int max2(int a,int b){ return (a>b)?a:b;}
