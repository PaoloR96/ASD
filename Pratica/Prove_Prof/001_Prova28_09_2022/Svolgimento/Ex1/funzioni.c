#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*Var globale*/
int DP[MAX_SIZE];
int CalcolaDP(int Seq[MAX_SIZE], int dp[MAX_SIZE],int n){
    int MaxSomma=0;
    //1_Caso base:
    DP[0]=0;
    //2_Ricorrenza:
    for (int i = 1; i < n; i++){
        //Prendo il massimo tra l'elemento attuale e dell'attuale+precedente 
        DP[i]=max2(Seq[i],Seq[i]+DP[i-1]);
        //Aggiorno il massimo calcolato ad ogni operazione i
        if (DP[i]>MaxSomma)MaxSomma=DP[i];
    }
    return MaxSomma;
}
int max2(int a,int b){return (a>b)? a:b;}