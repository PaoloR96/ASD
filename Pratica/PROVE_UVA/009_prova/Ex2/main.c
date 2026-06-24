#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    // inizializzazione dei test
    TestCase tests[] = {
        {4, 6, {4, 3, 2, 2, 1, 1}},   // t=4, n=6, lista di 6 numeri
        {5, 4, {2, 1, 1, 1}},         // t=5, n=4
        {400, 12, {50, 50, 50, 50, 50, 50, 25, 25, 25, 25, 25, 25}} // t=400, n=12
    };
    int num_tests = 3;
    printf("SAMPLE INPUT:\n");
    for(int i = 0; i < num_tests; i++) {
        printf("Test %d:\n", i + 1);
        stampaTestCase(tests[i]);
        printf("\n");
    }
    printf("SAMPLE OUTPUT:\n");
    for(int i = 0; i < num_tests; i++) {
        //Per ogni caso di test definisco le seguenti variabili
        int attuale[100];
        int SommaCorrente = 0;
        int trovato = 0;
        printf("SUM OF %d:\n",tests[i].t);
        trovaSomme(tests[i].x,tests[i].n,tests[i].t, 0,attuale, 0, SommaCorrente, &trovato);
        if (!trovato)printf("NONE\n");
        
    }
    
    system("pause");
    return 0;
}
/*Complessità:O(2^N)*/