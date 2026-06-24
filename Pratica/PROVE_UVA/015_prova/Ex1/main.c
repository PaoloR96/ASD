#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoTest T[MAX];
    int index=0;
    int TmpDim=0;
    printf("SAMPLE INPUT:\n");
    while (index<=MAX){
        //Definisco la dimesione della sequenza
        scanf("%d",&TmpDim);
        if(TmpDim==0)break;
        T[index].dim=TmpDim;
        //Inserisco la sequenza
        for (int i = 0; i < TmpDim; i++)scanf("%d",& T[index].Seq[i]);
        //Passo al caso successivo
        index++;
    }
     printf("SAMPLE OUTPUT:\n");
     int end=index;
     index=0;
     while (index<end){
            Merge(T[index].Seq,0,T[index].dim-1);
            StampaSeq(T[index].Seq,T[index].dim);
            index++;
     }
     
    
   

    system("pause");
    return 0;
}