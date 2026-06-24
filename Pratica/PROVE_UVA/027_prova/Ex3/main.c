#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    CasoTest T;
    Risultato ris[100];
    int index=0,t=0;
    int prezzo;
    scanf("%d",&t);
    while (index<t){
        //1.Riempio il caso di test corrente
        //a.Inserisco il prezzo dell'oggetto
        scanf("%d", &prezzo);
        //b.Inserisco numero di monete a disposizione
        scanf("%d",&T.n);
        for (int i = 0; i <T.n ;i++)scanf("%d",&T.Monete[i]); // Valore di ogni singola moneta
        //2.Inizializzo la DP
        InitDp(DP);
        //3.Calcolo la DP
        ris[index]=CalcolaDP(DP,T.Monete,T.n,prezzo);
        //passo al caso di test successivo
        index++;    
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++)printf("%d %d",ris[i].importoTot,ris[i].n);
    
   

    system("pause");
    return 0;
}

/*
ricorrenza: per ogni i che va da moneta al valore max : DP[j]=min2(DP[j],1+DP[j-monetax]); 
complessità:O(numMonete*K) con k intervallo che va(Max,monetax)


*/