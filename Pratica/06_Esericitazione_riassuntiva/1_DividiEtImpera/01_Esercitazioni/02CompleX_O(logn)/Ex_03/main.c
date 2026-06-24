#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int size = 10;
    int A[size];
    printf("Riempi Vettore: ");
    RiempiVettore(A, size);
    printf("\n");
    int k = DefinisciShift(A, 0, size - 1);  // k = indice del minimo
    int shift = (size - k) % size;           // vero numero di shift a sinistra
    printf("Il valore K (shift) e' pari a = %d\n", shift);
    system("pause");
    return 0;
}
/*Complessità O(logn)*/