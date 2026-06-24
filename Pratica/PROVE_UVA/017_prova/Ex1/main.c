#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Test T[MAXl];
    int index=0;
    int TmpTest;
    printf("SAMPLE INPUT:\n");
    while (index<MAXl&& scanf("%d",&TmpTest)==1){
        RiempiCasoTest(&T[index],TmpTest);
        qsort(T[index].N,T[index].numLibri, sizeof(int), ComparaN);
        printf("\n");
        index++;
    }
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < index; i++){
        CercaDifferenzaMin(T[i].N,T[i].numLibri,T[i].M);
    }

    system("pause");
    return 0;
}

/*Complessità.O(N*logN)*/