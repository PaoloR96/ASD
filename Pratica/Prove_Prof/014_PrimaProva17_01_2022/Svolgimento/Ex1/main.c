#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
   int dim=0,test=0;
   int index=0;
   int A[MAX],Ris[MAX];
   
   printf("SAMPLE INPUT:\n");
   while (index<MAX){
        //1.Inserisco la dimensione e gli elementi
        scanf("%d",&dim);
        if(dim==0)break;
        InserisciElementi(A,dim);
        //2.Calcolo le occorrenze
        Ris[index]=DividiSequenza(A,0,dim-1);
        //3.Passo al prossimo caso di test
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d\n",Ris[i]);
    system("pause");
    return 0;
}

/*
Complessità: O(casiTest*NlogN)
*/