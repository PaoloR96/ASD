#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int M[N][N] = {
        {0, 2,0,0},
        {0, 0,3,0},
        {4, 0,0,0},
        {0, 0,0,1}
    };
    printf("Matrice da riempire:\n");
    StampaMatrice(M);
    printf("\n");
    Sudoku(M);

    system("pause");
    return 0;
}
