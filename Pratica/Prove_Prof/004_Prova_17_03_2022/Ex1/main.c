#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int Test=0;
    int H[MAX],N[MAX];
    int Sequnza[MAX];
    scanf("%d",&Test);
    //Per ogni caso di test definisco(N,H),rispettivamente dimensione e distanza
    for (int i = 0; i<Test; i++)scanf("%d %d",&N[i],&H[i]);
    
    
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < Test; i++)CalcolaDistanzaHamming(Sequnza,N[i],H[i],0);
   

    system("pause");
    return 0;
}

/*
Complessità:O( N! / (H! * (N-H)!) )
Questa complessità deriva dal fatto che l’algoritmo genera lo spazio delle soluzioni contenente tutte le possibili combinazioni. 
Tuttavia, grazie alla tecnica di potatura (pruning), vengono considerate soltanto le combinazioni 
che soddisfano i vincoli H > 0(inserimento 1) e SpazioDisp >H (inserimento 0)

*/