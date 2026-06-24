#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Test=0,Risultato[100];
    
    int x=0,n=0;
    scanf("%d",&Test);
    for (int i = 0; i < Test && i<100; i++){
        scanf("%d %d",&x,&n);
        Risultato[i]=CalcolaExp(x,n);

    }
    
    printf("SAMPLE OUTPUT: \n");
      for (int i = 0; i < Test; i++)printf("%d \n",Risultato[i]);
   

    system("pause");
    return 0;
}

/*Complessità:O(logn)*/