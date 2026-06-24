#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funzioni.h"  // Include il file header
int DP[MAX_DP];
void InitDP(int DP[MAX_DP],int limite){
    for (int i = 0; i < limite; i++)DP[i]=INT_MAX;
}
int min2(int a,int b){return (a<b)?a:b;}


int ValoreMax(int n,int Monete[MAX_MONETE]){
    //Determina la moneta con il valore più alto
    int max_moneta = 0;
    for (int i = 0; i < n; i++) {
        if (Monete[i] > max_moneta) max_moneta = Monete[i];
    }
    return max_moneta;
}

int CalcolaDP(int DP[MAX_DP],int V,int limiteMax,int n,int Monete[MAX_MONETE]){
    //1.Caso base:
    DP[0]=0;
    //2.Ricorrenza
    for (int i = 0; i < n; i++){//Per ogni moneta i
        int monetaX=Monete[i];
        for (int j = monetaX; j <= limiteMax; j++){//per ogni elemento j vado a considerare tutti i possibli resti considerando più volte la stessa moneta
            //Se il nuovo stato ottenuto sottrando monetaX è raggiungibile allora:
            if(DP[j-monetaX]!=INT_MAX) DP[j]=min2(DP[j],DP[j-monetaX]+1);//Considero se prendere o non prendere la moneta per formare l'importo V
        }
    }
   // 3. Scansiona partendo dall'importo V a salire per trovare il primo risultato valido
    for (int k = V; k <= limiteMax; k++) {
        if (DP[k] != INT_MAX) return DP[k];
    }
    return -1;
}
