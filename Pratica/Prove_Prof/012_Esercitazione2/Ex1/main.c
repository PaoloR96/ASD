#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int Ris[100];
    int index=0,test=0;
    int I=0,D=0;
    scanf("%d",&test);
    while (index<test){
        scanf("%d %d",&D,&I);
        Ris[index]=TrovaPosizionePallina(1,I,D,1);
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++)printf("%d \n",Ris[i]);
    
    system("pause");
    return 0;
}
/*
Complessità: O(casiTest*D) dove D rappresenta la profondità
*/