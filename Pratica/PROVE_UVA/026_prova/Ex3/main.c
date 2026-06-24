#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    Blocco B[MAX];
    int dimB=0;
    int Risultato[MAX];
    int index=0;
    while (index<MAX){
        //1.Definisco il numero di blocchi
        scanf("%d",&dimB);
        if(dimB==0)break;
        //2.Inserisco i blocchi:Ogni tipo di blocco genera 3 orientamenti
        RiempiBlocchi(B,dimB);
        int numTotaleVarianti = dimB * 3;
        //3.Ordino i blocchi in base alla base
       qsort(B, numTotaleVarianti, sizeof(Blocco), ComparaBlocchi);
        //4.Inizializzo DP
        InitDP(DP_H,B,numTotaleVarianti);
        //5.Calcola Valore Max
        Risultato[index]=CalcolaDP(DP_H,B,numTotaleVarianti);

        //.passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("Case%d:maximumheight= %d \n",i+1,Risultato[i]);
    
    system("pause");
    return 0;
}



/*
complessità:O(numeriTest*n^2) dove n=numeroBlocchi*(blocchi_precedenti); 
Ricorrenza:  
            Per ogni j precedente ad i
                se (lunghezzax<B[j].lunghezza && larghezzax<B[j].larghezza ) 
                    DP_H[i]=max2(DP_H[i],DP_H[j] + B[i].h);


*/