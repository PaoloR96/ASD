#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
/*VAR GLOBALE*/
int DP[MAX][MAX];

void InitDP(int DP[MAX][MAX],int n, int m){
    //Inizializzo la mia DP[n][m] con n ed m dimensione delle due stringhe a 0
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++)DP[i][j]=0;
    }
}
int CalcolaDP(int DP[MAX][MAX],char Stringa1[MAX],int n,char Stringa2[MAX] ,int m){
        for (int i = 1; i <= n; i++){//Per ogni carattere i della Stringa1
            char carattereX=Stringa1[i-1];
            for (int j = 1; j <= m; j++){//per ogni carattere j della Stringa2
                if (carattereX==Stringa2[j-1]){
                    //Prendo il carattere
                    DP[i][j]=1+DP[i-1][j-1];
                }else{
                    //Prendo il uno dei due
                    DP[i][j]=max2(DP[i-1][j],DP[i][j-1]);
                }
            }
        }
        return DP[n][m];
}

int max2(int a,int b){return (a>b)?a:b;}