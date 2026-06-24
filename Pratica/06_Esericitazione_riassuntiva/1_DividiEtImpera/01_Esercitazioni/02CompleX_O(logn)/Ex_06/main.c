#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int size=10;
    int A[size];
    printf("Riempi Vettore:");
    RiempiVettore(A, size);
    printf("\n");
    int k=TrovaValore(A,0,size-1);
    printf("Valore k= %d\n", k);
    system("pause");
    return 0;
}
/*Complessità T(n)=O(logn)*/