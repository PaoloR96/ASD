#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int index=0;
    int A[MAX],Risultato[MAX];
    int test=0,k=0,dim=0;
    scanf("%d",&test);
    while (index<test){
            //definisco il parametro k e la dim del vettore
            scanf("%d %d",&k,&dim);
            //inserisco i parametri del vettore
            for (int i = 0; i < dim; i++)scanf("%d",&A[i]); 
            //trovo le occorrenze
            Risultato[index]=CalcolaOccorrenza(A,0,dim-1,k);
            //passo al prossimo caso di test
            index++;
    }
    
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d \n",Risultato[i]);
    
    system("pause");
    return 0;
}

/*
Complessità: O(casiTest*N)
*/