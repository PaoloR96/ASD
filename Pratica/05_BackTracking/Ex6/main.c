#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
     int matrice[N][N]; // definizione della matrice
     InitMatrice(matrice);
     StampaMatrice(matrice);
     printf("\n");
     risolviNRegine(matrice);
    


    system("pause");
    return 0;
}
