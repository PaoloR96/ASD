#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"  // Include il file header
int DP[MAX];
Risultato CalcolaDP(int DP[MAX],int Monete[MAX],int numM,int prezzoOggetto){
    //0.Inizializzo la variabile risultato e DP[0]
    Risultato r={0,0};
    DP[0]=0;
    //1.Calcolo DP
    for (int i = 0; i < numM; i++){//per ogni moneta i
        int monetax=Monete[i];
        //Partendo dal max fino al valore monetax, in quanto posso usare più volte la stessa moneta , quindi c'è ripetizione
        for (int j = MAX; j >=monetax; j--){
            if(DP[j-monetax]!=INT_MAX)DP[j]=min2(DP[j],1+DP[j-monetax]);
        }
    }
   //2. Ricerca del minimo importo pagabile >= prezzoOggetto 
    for (int i = prezzoOggetto; i < MAX; i++) {
        if (DP[i] != INT_MAX) {
            r.importoTot = i;
            r.n = DP[i];
            break; 
        }
    }
    return r;
}

void InitDp(int DP[MAX]){
    for (int i = 0; i < MAX; i++)DP[i]=INT_MAX;
}

int min2(int a,int b){
    return (a<b)?a:b;
}