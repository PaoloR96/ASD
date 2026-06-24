#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main() {
    int matrix[N][N] = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0}
    };

    printf("Matrice originale:\n");
    stampaMatrice(matrix);

    TrovaSottoMatrice(matrix);

    system("pause");
    return 0;
}

