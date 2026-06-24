#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    CasoTest Test[TEST_MAX];
    int test=0;
    printf("SAMPLE INPUT:\n");
    scanf("%d",&test);
    RiempiCasiDiTest(Test,test);
    printf("SAMPLE OUTPUT:\n");
    ElaboraCasiDiTest(Test,test);

   

    system("pause");
    return 0;
}

/*Complessità:O(n+m) per ogni caso di test con n=numero di nodi ed m numero di archi*/