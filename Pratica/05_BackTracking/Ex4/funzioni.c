#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header

void GeneraInsiemi(int S[],int n){
        int s[n];
        Backtraking(S,s,0,0,n);
}

void StampaInsiemi(int S[], int posCorr) {
    printf("[ ");
    for (int i = 0; i < posCorr; i++) {
        printf("%d ", S[i]);
    }
    printf("]\n");
}




void Backtraking(int S[],int s[],int start,int pos,int n){
        /*Stampa Insiemi*/
        StampaInsiemi(s,pos);
        /*genero i sotto-insiemi*/
        for(int i = start; i < n; i++){
           s[pos]=S[i];
           Backtraking(S,s,i+1,pos+1,n);
        }     
}

