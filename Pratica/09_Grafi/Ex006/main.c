#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoDiTest test[100]; 
    int index = 0, n = 0, l = 0;

    // Legge il numero di nodi n 
    printf("SAMPLE INPUT:\n");
    while (scanf("%d", &n) == 1 && n != 0) {
        // Legge il numero di archi l 
        if (scanf("%d", &l) == 1) {
            test[index].n = n;
            test[index].l = l;
            //riempio il caso di test
            RiempiCasoTest(&test[index], l);
            index++;
        }
    }
    printf("SAMPLE OUTPUT:\n");
    ElaboraCasi(test,index);
    system("pause");
    return 0;
}

/*Complessità:O(V+E)*/