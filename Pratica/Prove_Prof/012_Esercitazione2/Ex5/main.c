#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    Query query[MAX];
    Biglie biglie[MAX];
    int test=0,index=0;
    int TmpB=0,TmpQ=0;
    int i=0;
    //A:Inserisco gli elementi
    while (1){
        //Fase1:Inserisco le dimensioni
        scanf("%d %d",&TmpB,&TmpQ);
        if(TmpB==0 && TmpQ==0)break;
        //Fase2:Inserisco le biglie
        biglie[i].dimB=TmpB;
        RiempiElementi(biglie[i].B,biglie[i].dimB);
        //Fase3:Inserisco le query
        query[i].dimQ=TmpQ;
        RiempiElementi(query[i].Q,query[i].dimQ);
        //Fase4:Passo al caso di test successivo
        i++;
    }
    int dim=i;
    //B:Genero l'output
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < dim; i++){
        //Fase 1:Ordino le biglie come richiesto dal problema per il caso di test iesimo
        qsort(biglie[i].B, biglie[i].dimB, sizeof(int), ComparaElementi);
        //Fase 2:trovo gli elementi per il caso iesimo
        printf("CASE# %d:\n",i+1);
        TrovaElmento(biglie[i].B,biglie[i].dimB,query[i].Q,query[i].dimQ);
    }
    system("pause");
    return 0;
}