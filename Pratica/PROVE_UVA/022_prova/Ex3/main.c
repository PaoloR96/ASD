#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoTest T;
    Risultato risultato[MAX_T];
    int casiTest=0;
    printf("SAMPLE INPUT: \n");
    scanf("%d",&casiTest);
    for (int i = 0; i < casiTest && i<MAX_T ; i++){
        //1.Riempio il caso di test iesimo
        RiempiCasoTest(&T);
        //2.Inizializzo la DP
        int DP[MAX_S][MAX_S];
        InizializzaDP(DP,T.S);
        //3.Calcolo la DP
        CalcolaDP(DP,T);
        //4.Calcolo il risultato
        risultato[i]=TrovaSoluzioneOttima(DP,T);
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < casiTest; i++){
        /* code */
        if (risultato[i].stato==false){
            printf("NOT POSSIBLE! \n");
        }else{
            printf("%d \n",risultato[i].valore);
        }
        
    }
    system("pause");
    return 0;
}

/*
Complessità:(casiTest*N) dove N=m*S^2 m numero di monete ed S^2 per difinire i^2+j^2=S^2

Ricorrenza:DP[i][k]=min2(DP[i][k],DP[i-vx][k-vy]+1); 
*/