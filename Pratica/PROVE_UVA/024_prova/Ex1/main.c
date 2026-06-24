#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int m[100], n[100];
    int mTmp=0,nTmp=0;
    int index=0;
    while (index<100){
        scanf("%d %d",&mTmp,&nTmp);
        if(mTmp==1 && nTmp==1)break;
        m[index]=mTmp;
        n[index]=nTmp;
        //passo al caso successivo
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for (int i = 0; i < index; i++){
        idx=0;
        for (int i = 0; i < 2000; i++)Risultato[i]=0;
        Nodo L = {0, 1}; // Confine sinistro iniziale
        Nodo R = {1, 0}; // Confine destro iniziale
        CalcolaSequenza(m[i],n[i],R,L);
        StampaSequenza();
    }
    system("pause");
    return 0;
}

/*Complessità:O(N)*/