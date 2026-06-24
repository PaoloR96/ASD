#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int labirinto[N][N] = {
         {1, 1, 1, 1},
         {1, 0, 0, 1},
         {1, 1, 1, 1},
         {0, 0, 1, 1}
    };

    printf("Labirinto:\n"); 
    StampaMatrice(labirinto);
    printf("\n");
    TrovaNSoluzioni(labirinto);
    system("pause");
    return 0;
}
