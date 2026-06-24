#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int index=0,test=0;
    /*
    somma = S ;lunghezza sequenza = N ;numeri primi= P
    */
    int S[MAX],N[MAX],P[MAX];
    scanf("%d",&test);
    while (index<test){
        //inserisco i parametri 
        scanf("%d %d %d",&S[index],&N[index],&P[index]);
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    int Insieme[MAX];
    for (int i = 0; i < test; i++){
        printf("CASO DI TEST %d\n", i+1);
        CalcolaSequenza(Insieme,S[i],N[i],P[i],0,0);
    }
    
    system("pause");
    return 0;
}

/*
Complessità: O((K choose N)), dove K è il numero di numeri primi compresi tra P+1 e S
                              N la dimensione della sequenza

Il numero massimo di combinazioni è dato da questo prodotto binomiale
*/