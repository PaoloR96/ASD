#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALE*/
int DP[MAX_DP];

/*Definisco la dimensione ed le monete*/
void RiempiVettore(CasoTest *ct){
    scanf("%d",&ct->M);
    for (int i = 0; i < ct->M; i++){
        scanf("%d",&ct->ValoreMoneta[i]);
    }    
}

int max2(int a,int b){return(a>b)?a:b;}

/*Inizializzo la matrice DP a 0*/
void InitDP(int DP[MAX_DP]){
    for (int i = 0; i < MAX_DP; i++) DP[i]=0;
}

int CalcolaDP(int DP[MAX_DP],CasoTest ct,int target){
    //Creo la ricorrenza
    for (int i = 0; i < ct.M; i++){//Per ogni moneta i
        int MonetaX=ct.ValoreMoneta[i];
        for (int j = target; j >=MonetaX ; j--){
            DP[j]=max2(DP[j],DP[j-MonetaX]+MonetaX);
        }
    }
    return DP[target];
}

int SommaMonete(CasoTest ct){
    int SommaT=0;
    for (int i = 0; i < ct.M; i++)SommaT+=ct.ValoreMoneta[i];
    return SommaT;
}