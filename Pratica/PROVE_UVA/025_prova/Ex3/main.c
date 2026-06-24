#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funzioni.h"  // Include le funzioni definite in funzioni.c

int main() {
    int M[N][N];
    printf("SAMPLE INPUT: \n");
    //1.Inizializzo  e riempio la mia Matrice
    memset(M, 0, sizeof(M));
    RiempiMatrice(M,8);
    //2.Applico la dp
    printf("SAMPLE OUTPUT: \n");
    InizializzaDP(DP_H);
    int val= CalcolaDp(DP_H,M);
    printf("%d",val);
   

    system("pause");
    return 0;
}

/*
Complessità:O(N^3)

  se la cella è 1  allora      DP_H[i][j] = DP_H[i-1][j] + 1; 
                   altrimenti  DP_H[i][j]=0;//azzero altezza

*/