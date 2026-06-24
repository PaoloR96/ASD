#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Test=0,Risultato[100];
    /*
    D=profondità
    I=Iesima Pallina
    */
    int D=0,I=0;
    scanf("%d",&Test);
    for (int i = 0; i < Test && i<100; i++){
        scanf("%d %d",&D,&I);
        Risultato[i]=CalcolaPosizione(I,D,1,1);

    }
    
    printf("SAMPLE OUTPUT: \n");
      for (int i = 0; i < Test; i++)printf("%d \n",Risultato[i]);
   

    system("pause");
    return 0;
}

/*Complessità:O(logn)*/