#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
int main() {
    //definisco il caso di test
    CasoTest test[MAX_TEST];
    int index=0;
    int T=0;
    //1.Definisco i campioni di input
    printf("SAMPLE INPUT:\n");
    scanf("%d",&T);
    while (T!=0){
            //1.a Inserimento oggetti
            scanf("%d",&test[index].n);
            for (int i = 0; i < test[index].n; i++)scanf("%d %d",&test[index].oggetti[i].prezzo,&test[index].oggetti[i].peso);
            //1.b Inserimento capacità max peso che una  persona può sopportare
            scanf("%d",&test[index].g);
            for (int i = 0; i < test[index].g; i++)scanf("%d",&test[index].maxPeso[i]);
            //1.c Passo al caso di test successivo
            index++;
            T--;
    }
    //2.Elaborazione dell'output
    printf("SAMPLE OUTPUT:\n");
    T=index;
    index=0;
    while (T!=0){
        //2.a Inizializzo DP[MAX_MW]
        //per ogni caso di test inizializzo DP
        int DP[MAX_MW];
        initDP(DP,MAX_MW+1); 
        //2.b Risolvo il problema dello zaino 0/1
        CalcolaDP(DP,test[index]);   
        //2.c Psso al caso di test successivo
        index++;
        T--;
    }
    system("pause");
    return 0;
}


/*
Ricorrenza: DP[j]=max(prezzoAtt+DP[j-pesoAtt],DP[j]);

Complessità:O(T*(N* (MAX_MW + G)),dove:
    T: Rappresenta il numero di casi di test
    N*MAX_MW: Costo della funzione pe calcolare DP
    G: Numero di persone nella famiglia
*/