#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("SAMPLE INPUT:\n");
    int N=5,dim=3;
    int Matrice[MAX][MAX];
    for (int i = 0; i < dim; i++){
        RiempiElementi(Matrice[i],N);
    }
     printf("SAMPLE OUTPUT:\n");
     for (int i = 0; i < dim; i++){
       PancakeSorting(Matrice[i],N);
    }
    system("pause");
    return 0;
}

/*
Complessità:O(N^2)
*/