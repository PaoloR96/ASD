#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int A[SIZE][SIZE];
    int k[SIZE], size[SIZE];
    int T = 0, index = 0;
    printf("SAMPLE INPUT:\n");
    scanf("%d", &T);
    while(T != 0){
        scanf("%d %d", &size[index], &k[index]);
        RiempiVettore(A[index], size[index]);
        index++;
        T--;
    }
    printf("SAMPLE OUTPUT:\n");
    CalcolaSequenze(A, size, k, index);
    system("pause");
    return 0;
}
/*
T(n)=O(n · log S), dove:
    n è il numero di libri,
    S è la somma totale delle pagine o, equivalentemente, il range tra il libro più lungo e la somma totale.*/