#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    int size=10;
    int A[size];
    printf("Definisci valori giornalieri delle azioni (%d giorni):\n",size);
    RiempiVettore(A, size);
    TrovaQuotazioni(A,0,size-1);
    system("pause");
    return 0;
}
/*Complessità O(logn)*/