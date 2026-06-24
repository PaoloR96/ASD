#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int dimTest = 0;
    CasoTest test[MAX];
    printf("SAMPLE INPUT:\n");
    // Leggo il numero di casi di test
    if (scanf("%d", &dimTest) != 1) return 0;
    printf("\n");

    // Riempio e analizzo i dati seguendo la tua suddivisione
    RiempiCasoDiTest(test, dimTest);
    printf("SAMPLE OUTPUT:\n");
    ElaboraCasiDiTest(test, dimTest);
    system("pause");

    return 0;
}
/*Complessità_O(n+m)*/

