#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
int main() {
    CasoTest T;
    int index=0,lTmp=0;
    int Risultato[MAX_N];
    printf("SAMPLE INPUT: \n");
    while (index<5){
        scanf("%d",&lTmp);
        if(lTmp==0)break;
        InserisciCasoTest(&T,lTmp);
        InizializzaDP(DP,T.n);
        Risultato[index]=CalcolaDP(DP, T.punti,T.n);
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++)printf("The minimum cutting is %d \n",Risultato[i]);
    
    system("pause");
    return 0;
}

/*
Complessità:O(N^3)

// La formula di ricorrenza: DP[i][j] = min2(DP[i][j], costo_attuale),dove:
                costo_attuale = DP[i][k] + DP[k][j] + (P[j] - P[i]);
                // 1. DP[i][k]: costo minimo per tagliare la parte sinistra.
                // 2. DP[k][j]: costo minimo per tagliare la parte destra.
                // 3. (P[j] - P[i]): costo del taglio attuale (lunghezza del bastone corrente).
*/