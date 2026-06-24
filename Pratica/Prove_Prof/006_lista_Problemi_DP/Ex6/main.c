#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    Posizione P[MAX];
    int Risultato[MAX];
    int index=0,numeroTest=0;
    int dim=0;
    //1.Inserimento dei casi di test
    scanf("%d",&numeroTest);
    while (index<numeroTest){
        //1.A:Definisco la dimensione ed inserisco rispettivamente i valori di X ed Y
        scanf("%d",&dim);
        for (int i = 0; i < dim; i++)scanf("%d",&P[i].X);
        for (int i = 0; i < dim; i++)scanf("%d",&P[i].Y);
        //2.B:Odino Posizione P a partire da X crescente
        qsort(P,dim,sizeof(Posizione),ComporaValori);
        //3.C:Applico la logica DP
        InitDP(DP,dim);
        int Y[MAX];
        //4.D:Copio i valori di Y in un vettore di int 
        for (int i = 0; i < dim; i++)Y[i]=P[i].Y;
        //5.E:Calcolo il numero max di collegamenti
        Risultato[index]=CalcolaDP(DP,Y,dim);
        //6.F:Passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (size_t i = 0; i < index; i++)printf("%d \n", Risultato[i]);
    
    system("pause");
    return 0;
}

/*
COMPLESSITA': O(N^2)

RICORRENZA: DP[i]=max2(DP[i],DP[j]+1) SE posX>Y[j] dove posX=Y[i] per ogni j£(0,i) mentre i£(1,dim)

*/