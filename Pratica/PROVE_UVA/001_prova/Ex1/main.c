#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    Sequenza s;
    // precarichiamo i valori direttamente nella struct
    s.dati[0] = -5;
    s.dati[1] = -2;
    s.dati[2] = 2;
    s.dati[3] = -30;
    s.dim = 4;  // numero di elementi presenti

    //1.Stampa Sequenza
    printf("SAMPLE INPUT:\n");
    stampaSequenza(s);
    printf("SAMPLE OUTPUT:\n");
     //2.Calcola e stampa soluzione
    int val=Merge(s.dati,0,s.dim-1);
    printf("%d",val);
    system("pause");
    return 0;
}
/*
Complessità:O(n*log n).

*/