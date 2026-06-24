#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    printf("Caso di test1:\n");
    int labirinto[N][N] = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 0, 0, 1}
    };
    printf("Matrice del labirinto 5x5:\n\n");
    StampaLabirinto(labirinto);
    printf("\n");
    CalcolaPercorsoMin(labirinto);
    printf("\n");
    printf("Caso di test2:\n");
    int labirinto2[N][N] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    printf("Matrice del labirinto 5x5:\n\n");
    StampaLabirinto(labirinto2);
    printf("\n");
    CalcolaPercorsoMin(labirinto2);
    printf("\n");
    system("pause");
    return 0;
}
