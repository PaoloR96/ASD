#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioni.h"  // Include il file header

int CalcolaSequenza(char S1[MAX],char S2[MAX]){
        //1.Definisco la dimensione delle due stringhe
        int n=strlen(S1);
        int m=strlen(S2);
        //2.Inizializzo la DP
        int DP[MAX][MAX];
        InitDP(DP,n,m);
        //3.Calcola la sotto-sequenza
        int risultato=TrovaSequenza(DP,S1,S2,n,m);
        return risultato;
}
void InitDP(int DP[MAX][MAX],int n,int m){
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++)DP[i][j]=0;
    }
}

int TrovaSequenza(int DP[MAX][MAX],char S1[MAX],char S2[MAX],int n,int m){
    for (int i = 1; i <= n; i++){ //per ogni carattere i di S1
        for (int j = 1; j <= m; j++){ //per ogni carattere j di S2
            if (S1[i-1]==S2[j-1]){ //Se sono uguali 
                DP[i][j]=1+DP[i-1][j-1];
            }else{ //se sono diversi
                 DP[i][j]=max2(DP[i][j-1],DP[i-1][j]);
            }
        }
    }
    return DP[n][m];
}



int max2(int a,int b){
    return (a>b)? a:b;
}