#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int S[MAX],index=0;
    int DP[MAX],Risultato[MAX];
    int valore=0,numero=0;
    while (index<MAX){
            //1.Inserimento dei parametri
            scanf("%d",&valore);
            if(valore==-1)break;
            S[0]=valore;//salvo il valore per il caso di test
            //inserisco gli altri
            int dim=1;
            for(int i=1;i<MAX;i++){
                scanf("%d",&numero);
                if(numero==-1)break;
                S[i]=numero;//salvo il valore per il caso di test  
                dim++;
            }
            //2.Inizializzo la DP
            InizializzaDP(DP,dim);
            //3.Calcolo la DP
            Risultato[index]=CalcolaDP(DP,S,dim);
            //passo al caso di test sucessivo
            index++;       
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++){
        printf("Test #%d :maximumpossible interceptions:%d \n",i+1,Risultato[i]);
    }
    system("pause");
    return 0;
}


/*
Complessità_O(N^2)
Ricorrenza: DP[i]=max(DP[i],DP[j]+1) per ogni S[i] <= S[j] tale che vado a valutare
                                     tutti i missili j prima di i (j<=i)

*/