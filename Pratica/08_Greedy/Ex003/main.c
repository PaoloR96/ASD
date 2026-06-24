#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int t; // numero di scenari di test
    Scenario scenari[MAX_T];
    // PRECARICAMENTO valori
    t = 1;
    scenari[0].n = 6;
    scenari[0].prezzi[0] = 400;
    scenari[0].prezzi[1] = 100;
    scenari[0].prezzi[2] = 200;
    scenari[0].prezzi[3] = 350;
    scenari[0].prezzi[4] = 300;
    scenari[0].prezzi[5] = 250;
    //1. Stampa Scenario
    printf("SAMPLE INPUT:\n");
    stampaScenario(scenari[0]);
    //2.Ordinamento valori in senso decrescente 
    qsort(scenari[0].prezzi, scenari[0].n, sizeof(int), ComparaValori);
    stampaScenario(scenari[0]);
    //2.1Stampa valori ordinati
    //printf("SAMPLE INPUT_TMP:\n");
    //stampaScenario(scenari[0]);
     CalcolaSConto(scenari[0]);
   

    system("pause");
    return 0;
}
/*Complessità:O(n*logn)*/