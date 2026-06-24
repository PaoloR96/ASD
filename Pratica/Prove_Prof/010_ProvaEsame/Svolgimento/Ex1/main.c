#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    char Insieme[MAX];
    int ValoriN[TEST];
    int test=0;
    scanf("%d",&test);
    for (int i = 0; i < test; i++)scanf("%d",&ValoriN[i]);
    printf("SAMPLE OUTPUT:\n");
    for (int i = 0; i < test; i++){
        int n=ValoriN[i];
        // Pulizia della stringa non strettamente necessaria ma buona pratica
        memset(Insieme, 0, MAX * sizeof(char));
        // Il sample output richiede esattamente la stringa "TEST OUTPUT"
        printf("TEST OUTPUT:\n");
        // Chiamata iniziale: indice 0, e reverse impostato a 0
        CalcolaSequenza(Insieme, 0, n, 0);

    }
    system("pause");
    return 0;
}

/*
Comlessità O(N*2^N)
N=dipende dal for per convertire la stringa da intero a decimale
2^N = dipende dalla logica di backtacking;

NOTA: con la variabile flag spingo la logica ad andare a valutare la tupla(0,1) 

*/