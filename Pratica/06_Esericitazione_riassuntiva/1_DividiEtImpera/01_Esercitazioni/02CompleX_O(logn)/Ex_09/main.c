#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    
    int size=10;
    int A[size];
    printf("Riempi vettore:\n");
    RiempiVettore(A, size);
    TrovaValore(A,0,size-1);
    
    system("pause");
    return 0;
}
/*Complessità O(logn)*/