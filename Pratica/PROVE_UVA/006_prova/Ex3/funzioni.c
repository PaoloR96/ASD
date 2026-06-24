#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int Somma(int s[MAX_MONETE],int dim){
    int tot=0;
    for (int i = 0; i < dim; i++)tot+=s[i];
    return tot;
}

void InitDP(int dp[MAX_DP],int target){
    for(int i=0;i<target;i++)dp[i]=0;
}
int CalcolaDP(int dp[MAX_DP],int s[MAX_MONETE],int target,int m){
    //caso base: Setto a 1 dp[0],in quanto la somma 0 è ammissibile
    dp[0]=1;
    //caso iterativo:
    for (int x = 0;x < m; x++){// per ogni moneta x
        int monetaAtt=s[x];
        for (int i = target; i >= monetaAtt; i--){
             if(dp[i - monetaAtt] == 1)dp[i]=1; //prendo la monetaAtt
             //non la prendo la monetaAtt
        } 
    }
    //trovo il max
    for(int i=target;i>=0;i--){
        if(dp[i]==1)return i;
    }
    return 0;
     
}

