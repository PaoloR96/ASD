#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int test=0;
    int Y=0,dim=0;
    int Tempo[MAX];
    Risultato Ris[MAX];
    printf("SAMPLE INPUT:\n");
    scanf("%d",&test);
    for (int i = 0; i < test; i++){
        scanf("%d",&Y);
        scanf("%d",&dim);
        for (int i = 0; i < dim; i++)scanf("%d",&Tempo[i]);
        Ris[i]=TrovaMassimo(Tempo,dim,Y);
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < test; i++){
        printf("%d %d %d \n",Ris[i].numeroEventi,Ris[i].Window.start,Ris[i].Window.end);
        
    }
    
    system("pause");
    return 0;
}

/*
Complessità:O(k*MlogM) dove K=numeriTest*DIm

*/