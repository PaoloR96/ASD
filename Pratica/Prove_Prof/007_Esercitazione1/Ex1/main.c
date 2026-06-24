#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Risultato[MAX];
    int Visited[MAX][MAX];
    int index=0;
    int N=0;
    while (index<MAX){
            //1.Inserisco N
            scanf("%d",&N);
            if(N==0)break;
            //2.Inizializzo a 0 Visited
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++)Visited[i][j]=0;
            }
            //3.Calcolo le possibili combinazioni
            Contatore=0;
            PosizionaRegina(Visited,0,N);
            Risultato[index]=Contatore;
            //4.Passo al caso di test successivo
            index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d \n",Risultato[i]);
    
   
    system("pause");
    return 0;
}

/*Complessità:O(N!)*/