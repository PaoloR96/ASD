#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int A[SIZE][SIZE];  // Array 2D per più sequenze
    int n[SIZE];        // Dimensioni delle sequenze
    int index = 0;

    printf("SAMPLE INPUT:\n");
    while (1) {
        scanf("%d", &n[index]);
        if (n[index] == 0) break; // termina input
        RiempiVettore(A[index], n[index]);
        index++;
    }

    printf("SAMPLE OUTPUT:\n");
    CalcolaSwap(A, n, index);

    system("pause");  // pausa finale su Windows
    return 0;
}

/*Complessità O(n*logn)*/