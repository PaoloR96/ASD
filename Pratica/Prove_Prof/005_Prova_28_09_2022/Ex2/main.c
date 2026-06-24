#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT: \n");
    int N[100],index=0;
    int tmp=0;
    while (index<100){
        scanf("%d",&tmp);
        if(tmp==0)break;
        N[index]=tmp;
        //passo al caso di test successivo
        index++;
    }
    printf("SAMPLE OUTPUT: \n");
    for(int i=0;i<index;i++)StampaTriangolo(N[i]);
    system("pause");
    return 0;
}
/*Complessità:O(n)*/