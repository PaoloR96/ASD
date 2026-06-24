#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int index=0;
    int n=0,m=0;
    int vasi[MAX],risultato[MAX];
    while (index<2){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&vasi[i]);
        risultato[index]=calcolaCapacitaMinima(n,m,vasi);
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for(int i=0;i<index;i++)printf("%d \n",risultato[i]);
    system("pause");
    return 0;
}

/*
Complessità:O(n*log(sommaCapacità))
*/