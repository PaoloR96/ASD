#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoTest T[MAX];
    int index=0;
    printf("SAMPLE INPUT:\n");
    int mTmp=0,nTmp=0;
    while (index!=MAX){
            scanf("%d %d",&mTmp,&nTmp);
             if (mTmp == 0) break; //esco
             //aggiorno i valori
             T[index].m=mTmp; //definisco le colonne
             T[index].n=nTmp; //definisco le righe
             //inserimento dati
             InserimentoCasiTest(T[index].T,T[index].visitato,T[index].n,T[index].m);
             index++;//passo al prossimo caso di test
    }
    printf("SAMPLE OUTPUT:\n");
    ElaboraCasiTest(T,index);

    
   

    system("pause");
    return 0;
}



/*Complessità:O(N*M)*/