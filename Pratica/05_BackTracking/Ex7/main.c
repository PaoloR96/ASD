#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int labirinto[N][N] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int visitato[N][N] = {0};
    printf("Labirinto:\n"); 
    StampaMatrice(labirinto);
    printf("\n");
    printf("Percorso:\n");
    if(!TrovaPercorso(labirinto, 0, 0, visitato))printf("Nessun percorso trovato.\n");
    system("pause");
    return 0;
}
