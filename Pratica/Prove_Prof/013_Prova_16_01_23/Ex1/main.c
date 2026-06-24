#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int index=0,test=0;
    int Ris[MAX];
    CasoTest ct;
    scanf("%d",&test);
    while (index<test){
        //1.Riempio il vettore
        RiempiVettore(&ct);
        //2.Calcolo la somma 
        int sommaTotale=SommaMonete(ct);
        int target=sommaTotale/2;
        //3.Inizializzo la DP
        InitDP(DP);
        //4.Calcolo DP
        int ladro1=CalcolaDP(DP,ct,target);
        //5.Calcolo la differenza:Il primo ladro prende K il restante,il secondo invece: 
        Ris[index]=sommaTotale-2*(ladro1);
        //6.Passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d \n",Ris[i]);
   

    system("pause");
    return 0;
}
/*
Complessità: O(numeriTest*M*Target) dove M numero di monete

Ricorrenza: DP[j]=max2(DP[j],DP[j-MonetaX]+MonetaX); valuto se prendere o non prendere la monetaX
                  ciò vale per ogni j £(target,MonetaX)

*/