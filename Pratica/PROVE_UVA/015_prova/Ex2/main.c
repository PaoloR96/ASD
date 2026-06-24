#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int n[10],L[10];
    char SequenzaK[80];
    int index=0;
    while (scanf("%d %d", &n[index], &L[index]) == 2 && (n[index] != 0 || L[index] != 0)&& index<10)index++;
    printf("SAMPLE OUTPUT:\n");
    int end=index;
    index=0;
    while (index<end){
         conteggio = 0;
         CalcolaSequenza(SequenzaK,0,L[index],n[index]);
        index++;
    }
    system("pause");
    return 0;
}

/*Complessità:O(L^M) con L numero di lettere ed M=lunghezza max della sequenza*/