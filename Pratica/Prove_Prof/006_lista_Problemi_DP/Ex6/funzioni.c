#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int DP[MAX];
int ComporaValori(const void *a,const void *b){
   const Posizione *A=(const Posizione*)a;
   const Posizione *B=(const Posizione*)b;
   //Ordino per X crescente
   if(A->X != B->X)return A->X -B->X;
   // Se X è uguale, ordina per Y crescente
  return A->Y -B->Y;
}

int InitDP(int DP[MAX],int dim){
    for (int i = 0; i < dim; i++)DP[i]=1;
}

int CalcolaDP(int DP[MAX],int Y[MAX],int dim){
    int NumeroMAX=1;
    //Ricorsione:
    for (int i = 1; i < dim; i++){//per ogni posizione i, definisco il mio punto d'osservazione
        int posX=Y[i];
        for (int j = 0; j < i; j++){//vado a valutare il mio intervallo che parte da j=0 fino ad i
            if (posX>Y[j]){
                // Scegli se tenere la soluzione attuale per i 
                // o estendere la sottosequenza che terminava in j
                DP[i]=max2(DP[i],DP[j]+1);
            }
        }
        //dopo ogni ciclo j,aggiorno il massimoGlobale
        if(NumeroMAX<DP[i])NumeroMAX=DP[i];
    }
    return NumeroMAX;
}
int max2(int a,int b){return(a>b)?a:b;}