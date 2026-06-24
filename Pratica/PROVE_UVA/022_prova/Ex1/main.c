#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int Matrice[MAX][MAX];
    printf("SAMPLE INPUT: \n");
    Mappa M;
    RiempiMappa(&M);
     printf("SAMPLE OUTPUT: \n");
    ConvertiB_to_D(M.caratteri, Matrice, M.righe, M.colonne);
    CalcolaSequenza(Matrice, 0, M.righe-1, 0, M.colonne-1);
   

    system("pause");
    return 0;
}
/*Complessità: O(N)*/