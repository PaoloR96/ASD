#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c
extern int Contatore;
int main() {
    CasoTest T[MAX];
    int nTmp=0,index=0;
    printf("SAMPLE INPUT:\n");
    while (index!=MAX){
            scanf("%d",&nTmp);
            if(nTmp==0)break;;
            T[index].n=nTmp;
            RiempiCasoTest(T[index].Scacchiera,T[index].n);
            index++;
    }
    int end=index;
    index=0;
    printf("SAMPLE OUTPUT:\n");
    while (index!=end){
            Contatore=0;
            PosizionaRegina(T[index].Scacchiera,T[index].n,0);
            printf("Caso di Test %d: %d \n",index+1,Contatore);
            index++;
    }
   

    system("pause");
    return 0;
}

/*Complessit-:O(n!)*/