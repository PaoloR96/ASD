#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
        int Dh[MAX],answers[MAX];
        int dim=0,casoTest=0;
        printf("SAMPLE INPUT:\n");
        scanf("%d",&casoTest);
        for (int i = 0; i < casoTest; i++){
            
            scanf("%d",&dim);
            RiempiCasoTest(Dh,dim);
            answers[i]=RicercaBinariaK(Dh,dim);
        }
        printf("SAMPLE OUTPUT:\n");
         for (int i = 0; i < casoTest; i++)printf("case %d:%d \n",i+1,answers[i]);

        

        system("pause");
        return 0;
}

/*Complessità: O(N*logN)*/