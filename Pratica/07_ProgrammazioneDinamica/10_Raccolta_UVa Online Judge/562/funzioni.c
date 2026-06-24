#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"
int SommaMonete(int monete[], int m) {
    int somma = 0;
    for (int i = 0; i < m; i++)somma += monete[i];
    return somma;
}
void InitDp(int dp[],int n){
    for (int i = 0; i < n; i++)dp[i]=0;
}
int CalcolaDp(int monete[],int dp[],int target,int m){
    /*CasoBase:*/
    dp[0]=1;
    /*Ricorrenza:*/
    for (int moneta_x = 0; moneta_x < m; moneta_x++){
        int v = monete[moneta_x];
        for (int i = target; i >= v; i--){
            if (dp[i - v] == 1) dp[i] = 1;
        }
        
    }
    for (int i = target; i >= 0; i--){
            if (dp[i] == 1) return i;
        }
    return 0;
    
    
}